#!/usr/bin/env python

from functools import reduce
# apply a particular function passed in its argument to all of the list elements

list = [1,2,3,4]
a = reduce(lambda x,y: x+y, list)

# At first step, first two elements of sequence are picked and the result is obtained
# 1+2=3
# Next step is to apply the same function to the previously attained result and the number just succeeding the second element and the result is again stored.
# 3+3=6
# This process continues till no more elements are left in the container.
# The final returned result is returned.
# 6+4=10

print("sum=",a)
