'''
Author: LetMeFly
Date: 2022-08-11 12:13:08
LastEditors: LetMeFly
LastEditTime: 2022-08-11 16:52:03
'''
from bs4 import BeautifulSoup

def change1html(path):
    with open(path, "r", encoding="utf-8") as f:
        content = f.read()
        f.close()
    soup = BeautifulSoup(content, "lxml")
    head = soup.find("head")
    scriptTag = soup.new_tag(name="script")
    scriptTag.string = "window._LINKS_COMMONJS_NOTCHANGEICO = true;"
    head.append(scriptTag)
    scriptTag = soup.new_tag("script", src="https://letmefly.xyz/Links/Common.js")
    head.append(scriptTag)
    linkTag = soup.new_tag("link", attrs={
        "type": "image/x-icon",
        "rel": "shortcut icon",
        "href": "/favicon.ico"
    })
    head.append(linkTag)
    print(soup)
    with open(path + "lll", "w", encoding="utf-8") as f:
        print(f.writable())
        f.write(soup.prettify("utf-8"))


change1html("_site/index.html")
