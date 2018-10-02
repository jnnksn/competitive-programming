# https://dmoj.ca/problem/ccc17s2
# 05/21/2018
# ------------------------------------
# The Algorithm:
# We are given 3 important pieces of information:
# Tides alternate between low and high
# all high tide measurements > low tide
# high tides keep increasing and low tides decrease
#
# Simply, we can sort the given measurements from greatest to least
# then divide it equally into 2, where the lower half is for low tides, and the higher half is for high tides.
# The high tides are already in their ascending order, however low tides are not in their descending order.
# thus we then reverse sort the lower tides from greatest to least.
#
# lastly we iterate, displaying the value of the first index of the low tide array, then first index of high tide, then continue.
# ------------------------------------
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
