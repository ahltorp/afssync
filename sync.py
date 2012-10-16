#!/usr/bin/python

import arlalow
import pprint
import os
import sqlite3
import stat
import tempfile
import sys

from util import *
from afsutil import *
from syncutil import dosync, readbasefiles, getbasefilesdict

if len(sys.argv) != 2:
    print >> sys.stderr, "usage:", sys.argv[0], "<local directory>"
    sys.exit(1)
basepath = sys.argv[1]

conn = sqlite3.connect(basepath + "/.afssync/db.sqlite")
conn.row_factory = sqlite3.Row
cursor = conn.cursor()

cursor.execute('select volume, cell from config where seq = 1')
(volume, cell) = cursor.fetchone()




print "Initializing"

arlalow.init()

fs = fileserver(cell, volume)

wholetree = fs.traverse_remote_tree(fs.rootfid, "")

print "Fetched tree"

def allFileEntriesFromTree(tree):
    if "children" in tree:
        return [{"name": tree.get("name"), "fid":tree.get("fid"), "path":tree.get("path"), "parent":tree.get("parent")}] + [e for f in tree["children"] for e in allFileEntriesFromTree(f)]
    else:
        return [tree]

serverfiles = allFileEntriesFromTree(wholetree)

#print serverfiles

status = fs.getstatusforfids([e["fid"] for e in serverfiles])

for e in serverfiles:
    e["status"] = status[e["fid"]]

readbasefiles(cursor)

localfiles = [e for e in getlocalfiles(basepath) if not e["path"].startswith("/.afssync/")]
#print localfiles

#print
#print "local"
localfilesdict = dict([(e["path"], e) for e in localfiles])
#print localfilesdict.keys()


#print
#print "server"
serverfilesdict = dict([(e["path"], e) for e in serverfiles])
#print serverfilesdict.keys()

allfiles = sorted(set(localfilesdict.keys()) | set(getbasefilesdict().keys()) | set(serverfilesdict.keys()))

def fetchfile(basepath, serverfile):
    (fd, name) = tempfile.mkstemp(dir=basepath+"/.afssync/fetched")
    fid = serverfile["fid"]

    f = os.fdopen(fd, "wb")
    (status, checksum) = fs.getfile(fid, serverfile["status"]["length"], f)
    f.close()
    assert serverfile["status"]["length"] == status["length"]
    assert serverfile["status"]["dataversion"] == status["dataversion"]
    status["checksum"] = checksum
    return (name, status)



try:
    dosync(conn, cursor, allfiles, fs, localfilesdict, serverfilesdict, getbasefilesdict(), basepath)
finally:
    arlalow.giveupallcallbacks(fs.fsconn)

#while 1:
#    print "sleep"
#    arlalow.sleep()
