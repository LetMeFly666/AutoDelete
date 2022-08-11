'''
Author: LetMeFly
Date: 2022-08-11 21:26:08
LastEditors: LetMeFly
LastEditTime: 2022-08-11 21:26:08
'''
import os
toRemoveDir = [".vs", "x64", "x86"]
for i in os.walk('.'):
    dirPath = i[0]
    dirName = os.path.split(dirPath)[1]
    if dirName in toRemoveDir:
        cmd = "del {:1} /s /q /f".format(os.path.abspath(dirPath))
        print(cmd)
        os.system(cmd)
        cmd = "rd {:1} /s /q".format(os.path.abspath(dirPath))
        print(cmd)
        os.system(cmd)
