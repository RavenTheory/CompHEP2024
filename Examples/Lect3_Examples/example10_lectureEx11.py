#!/usr/bin/env python

nums0 = range(1,10)
for i in range(2,4):
    nums = filter(lambda x: x % i == 0, nums0)
    print(list(nums))
