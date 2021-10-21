#!/usr/bin/env python


import requests,os,getopt,sys
opts, args = getopt.getopt(sys.argv[1:],"hi:o:",["ifile=","ofile="])
track = ''
for i in args:
	track += i
uris = requests.get(f"https://elegant-croissant.glitch.me/spotify?q={track}&type=track").json()["tracks"]["items"]
c=0
for i in uris:
	c+=1
	print(c,i["name"],"by",i["album"]["artists"][0]["name"])
opn = input('OPTION : ')
uri = uris[int(opn)-1]["uri"]
url = uris[int(opn)-1]["external_urls"]["spotify"]

#/- for Linux :
#/- os.system(f"playerctl open {uri}")

#/- for Windows :
import webbrowser
webbrowser.open(url)

'''
SCRIPT BY AADITYARENGARAJAN (GitHub @aadityarengarajan or https://aaditya.intellx.co.in)

Script to Automatically Play a Spotify Track using PlayerCTL.
'''