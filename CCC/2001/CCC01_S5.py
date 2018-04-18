# https://dmoj.ca/problem/ccc01s5
# 04/17/2018
# 30/40 on DMOJ ~ Time Limit Exceeded

limit = int(input())
N = int(input())
a = []
b = []
num_index = []

for _ in range(N):
    a.append(input())
for i in range(N):
    b.append(input())
    num_index.append(i)

retVal = 0
retIn = []

def find(x, y, k, index):
    global retVal
    global retIn
    if x == y:
        retVal = k
        retIn = index.split()
        return True
    elif k >= limit:
        return False
    elif not y.startswith(x) and not x.startswith(y):
        return False
    else:
        for i in num_index:
            d = x + a[i]
            ka = y + b[i]
            find(d,ka, k+1, index + " " + str(i+1))

for i in num_index:
    find(a[i], b[i], 1, str(i+1))


if retVal == 0 and len(retIn) == 0:
    print("No solution.")
else:
    print(retVal)
    for j in retIn:
        print(j)   


