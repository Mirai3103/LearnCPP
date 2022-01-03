from os import walk
import os
import shutil
def getAllfileName(args):
    f = []
    for (dirpath, dirnames, filenames) in walk("args"):
        f.extend(filenames)
        break
    return f
goc = "./content/onedrive/kiniemc6/may_2_01"

subfolders = os.listdir(goc)

for folders in subfolders:
    path = goc+"/"+folders
    f = getAllfileName(path)
    for fileName in f:
        print(path+"/"+fileName)
        # shutil.move(path+"/"+fileName, goc)
    break


