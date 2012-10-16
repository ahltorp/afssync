import arlalow

from util import chunks, checksumcontents

def isdir(fid):
    return fid[1] % 2 == 1

class fileserver:
    def __init__(self, cell, volume):
        print "Looking up db servers"

        dbservers = arlalow.dbservers(cell)

        print "Got db servers", dbservers
        
        VLDB_SERVICE_ID=52
        FS_SERVICE_ID=1
        
        dbconn = arlalow.rxconn(dbservers[0], 7003, VLDB_SERVICE_ID)
        
        print "Got db connection", dbconn
        
        print volume, cell
        
        vlentry = arlalow.VL_GetEntryByNameN(dbconn, volume)
        
        print "Got vlentry", vlentry
        
        self.rootfid = (vlentry["ROVolumeId"] if vlentry["roexists"] else vlentry["RWVolumeId"], 1, 1)
        
        print self.rootfid
        self.fsconn = arlalow.getconnbyaddr(cell, vlentry["firstServer"], 7000, FS_SERVICE_ID)
        print "Got fs connection", self.fsconn

    
    def traverse_remote_tree(self, fid, path):
        dircontents = arlalow.fetchfile(self.fsconn, fid, 0, 1000000);
        directory = arlalow.parsedirectory(dircontents, fid)
        children = []
        for entry in directory:
            if isdir(entry["fid"]):
                if entry["name"] not in [".", ".."]:
                    childFileEntry = self.traverse_remote_tree(entry["fid"], path + "/" + entry["name"])
                    childFileEntry["name"] = entry["name"]
                    childFileEntry["parent"] = fid
                    children.append(childFileEntry)
            else:
                children.append({"name":entry["name"], "fid":entry["fid"], "path":path+"/"+entry["name"], "parent":fid})
        return {"fid":fid, "status":dircontents["status"], "children":children, "path":path+"/"}

    def getstatusforfids(self, fids):
        status = {}
        
        for chunk in chunks(fids, 50):
            for f in arlalow.fetchbulkstatus(self.fsconn, chunk):
                status[f["fid"]] = f["status"]
        return status

    def getfile(self, fid, length, localfile):
        contents = arlalow.fetchfile(self.fsconn, fid, 0, length)
        localfile.write(contents["contents"])
        return (contents["status"], checksumcontents(contents["contents"]))
