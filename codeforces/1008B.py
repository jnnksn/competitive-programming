# http://codeforces.com/contest/1008/problem/B
# 07/13/2018

n = int(input())
works = True
last = [99999999999999999]
for i in range(n):
    rec = [int(i) for i in input().split()]
    rec.sort()
    
    if rec[1] <= last[-1]:
        last.append(rec[1])
    elif rec[0] <= last[-1]:
        last.append(rec[0])
    else:
        works = False
        break

if works:
    print("YES")
else:
    print("NO")
