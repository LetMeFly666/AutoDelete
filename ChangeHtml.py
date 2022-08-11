'''
Author: LetMeFly
Date: 2022-08-11 12:13:08
LastEditors: LetMeFly
LastEditTime: 2022-08-11 12:33:13
'''
from bs4 import BeautifulSoup

def change1html(path):
    soup = BeautifulSoup(open(path, "r", encoding="utf-8").read(), "lxml")
    head = soup.find("head")
    scriptTag = BeautifulSoup.new_tag("script")
    scriptTag.text = "window._LINKS_COMMONJS_NOTCHANGEICO = true;"
    head.append(scriptTag)
    scriptTag = BeautifulSoup.new_tag("script", src="https://letmefly.xyz/Links/Common.js")
    head.append(scriptTag)
    linkTag = BeautifulSoup.new_tag("link", attrs={
        "type": "image/x-icon",
        "rel": "shortcut icon",
        "href": "/favicon.ico"
    })
    head.append(linkTag)
    print(soup)
    open(path, "w", encoding="utf-8").write(soup.prettify("utf-8"))


change1html("_site/index.html")
