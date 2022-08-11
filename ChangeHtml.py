'''
Author: LetMeFly
Date: 2022-08-11 12:13:08
LastEditors: LetMeFly
LastEditTime: 2022-08-11 12:19:51
'''
import os
print(os.system("tree"))

from bs4 import BeautifulSoup

def change1html(path):
    soup = BeautifulSoup(open(path, "r", encoding="utf-8").read())
    print(soup)

change1html("_site/index.html")
