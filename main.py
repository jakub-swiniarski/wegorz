import sys
import os
name = sys.argv[1]
print(name)

inp = open(name,"r")
wrd = open("wordlist.txt",'r')
out = open(name +"we.py", "a")

F_word = wrd.read().split("\n")

a = inp.read()

for x in F_word:
    xy = x.split(" ")
    if len(xy) == 2:
        a = a.replace(xy[1],xy[0])

out.write(a)

try:
    os.system("pyinstaller " + name +"we.py")
    os.remove(name +"we.py")
except:
    print("install pyinstaller (pip or pip3 install -U pyinstaller)")