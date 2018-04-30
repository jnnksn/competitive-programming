# https://dmoj.ca/problem/dmpg18b6
# 04/30/2018

N, K = [int(i) for i in input().split()]
widths = [int(i) for i in input().split()]
widths.sort()

tmp = []
tmp.append(widths[0])
for i in widths:
    print(tmp[-1] - i)
    if i - tmp[-1] >= K:
        tmp.append(i)

print(len(tmp))
