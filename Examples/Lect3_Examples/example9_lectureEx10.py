#!/usr/bin/env python

def square(number):
    return number*number

lsquare = lambda x: x*x

a = 5
print(a,"sq=",square(a),"(ftion def)")
print(a,"sq=",lsquare(a),"(lambda ftion)")
