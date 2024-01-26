#!/usr/bin/env python

from itertools import chain

m = 'A message'
colors = chain(range(30,39),range(40,47),range(90,99))
for color in colors:
    print("\033[%im"%color,m,"\033[0m","color=",color)
print("\033[1m",m,"\033[0m","bold font")
print("\033[3m",m,"\033[0m","italics")
print("\033[4m",m,"\033[0m","underline")

