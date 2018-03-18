# https://dmoj.ca/problem/ccc15s1
# 3/18/2018

N = int(input())
x = []
for i in range(N):
    tmp = int(input())
    if tmp == 0:
        del x[-1]
    else:
        x.append(tmp)

total = 0;
for k in range(len(x)):
    total += x[k]
print(total)
