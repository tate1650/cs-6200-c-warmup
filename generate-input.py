#!/usr/bin/env python3 

import random

for i in range(10000):
    nums = []
    for j in range(random.randint(100, 200)):
        nums.append(random.randrange(-10000, 10000))
    print(" ".join([str(n) for n in nums]))

