import hashlib
import os
import io
import stat

def checksumfile(path):
    m = hashlib.sha1()
    with open(path, "rb") as fd:
        s = fd.read(8192)
        while s != "":
            m.update(s)
            s = fd.read(8192)
    return "sha1:" + m.hexdigest()

def readwholefile(path):
    f = io.open(path, "rb", buffering=0)
    s = os.fstat(f.fileno())
    contents = bytearray(s.st_size)
    f.readinto(contents)
    f.close()
    return contents

def checksumcontents(contents):
    m = hashlib.sha1()
    m.update(contents)
    return "sha1:" + m.hexdigest()

def getlocalfileinfo(path, direntry):
    f = path + direntry["path"]
    s = os.lstat(f)
    #print "lookup:" + f
    return {"mode":s.st_mode, "mtime":int(s.st_mtime), "size":s.st_size}
    
def chunks(l, n):
    return [l[i:i+n] for i in range(0, len(l), n)]

def getlocalfiles(path):
    path = path.rstrip("/")
    filelist = []
    for root, dirs, files in os.walk(path):
        if not root.startswith(path):
            raise Exception
        root = root[len(path):]
        direntry = {"path":root + "/", "name": os.path.basename(root)}
        direntry.update(getlocalfileinfo(path, direntry))
        filelist.append(direntry)
        for filename in files:
            direntry = {"path":root + "/" + filename, "name":filename}
            direntry.update(getlocalfileinfo(path, direntry))
            filelist.append(direntry)
    return filelist

def mode_to_filetype(mode):
    if stat.S_ISREG(mode):
        return 1
    if stat.S_ISDIR(mode):
        return 2
    if stat.S_ISLNK(mode):
        return 3
    raise Exception("Unknown file type: mode %o", mode)

