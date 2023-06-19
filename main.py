import sys
name = sys.argv[0]

inp = open(name,"r")
wrd = open("wordlist.txt",'r')
out = open(name +".py", "a")

F_word = wrd.read().split("\n")
systm = ""
import os
from sys import platform
if platform == "linux" or platform == "linux2":
    systm = "python3"
elif platform == "darwin":
    systm = "python3"
elif platform == "win32":
    systm = "python"

a = inp.read()

for x in F_word:
    xy = x.split(" ")
    a = a.replace(xy[1],xy[0])
    
out.write(a)