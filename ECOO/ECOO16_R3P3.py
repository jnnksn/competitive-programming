# https://dmoj.ca/problem/ecoo16r3p3
# 08/01/2018
# ---------------------------------------------
# Honestly, I don't know what to say...
# Firstly, thanks to aeternalis1 for your solution!
# I had the EXACT same idea as both Andrew Dong and
# aeternalis1, but for some reason I couldn't implement!
# I spent too long, and it's really late! I started
# with python, but it wouldn't stop tleing.
# so turns out there is a faster input with python...
# when I used the faster input with my solution, it messes
# it up, so I guess I'll just use this one...
# ---------------------------------------------

# aeternalis solution;

import sys
input = sys.stdin.readline

N = int(input())
words = set([input().strip() for x in range(N)])

for i in range(10):
  string = input()
  length = len(string)
  array = [10000 for x in range(length+1)]
  array[0] = 0
  for j in range(length+1):
    for k in range(j):
      if string[k:j] in words:
        array[j] = min(array[j],array[k]+1)
  print(array[-2]-1)

'''
my solution (TLE)
  
d = []
n = int(input())
sw = 999999999

for i in range(n):
    st = input()
    sw = min(sw, len(st))
    d.append(st)


for _ in range(10):
    phrase = input()
    dp = [999999 for i in range(len(phrase)+5)]
    dp[0] = 0

    for i in range(len(phrase)):
        for j in range(i+sw, len(phrase)+1):
            if phrase[i:j] in d:
                dp[j] = min(dp[i]+1, dp[j])
        
  
    print(dp[len(phrase)]-1)
  '''
