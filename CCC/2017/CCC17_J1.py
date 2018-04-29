# https://dmoj.ca/problem/ccc17j1
# 04/28/2018

x = int(input())
y = int(input())
if x > 0 and y > 0:
    print(1)
elif x > 0 and y < 0:
    print(4)
elif x < 0 and y < 0:
    print(3)
elif x < 0 and y > 0:
    print(2)
