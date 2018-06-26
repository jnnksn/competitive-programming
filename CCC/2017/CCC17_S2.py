# https://dmoj.ca/problem/ccc17s2
# 05/21/2018

import math
N = int(input())
tides = [int(i) for i in input().split()]
tides.sort()

split = math.ceil(N/2)
low = tides[0:split]
low.sort(reverse=True)
high = tides[split:]

s = ""
for i in range(len(low)):
    s += str(low[i]) + " "
    if N%2 == 0 or i != len(low)-1:
        s += str(high[i]) + " "
        
print(s)
