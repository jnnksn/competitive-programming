# https://dmoj.ca/problem/ccc08s4
# 04/18/2018
# -------------------------------
# DAVID! YOU IDIOT YOU FORGOT
# ABOUT BEDMAS!??!?!?!
# -------------------------------
# 60/100 on DMOJ
# Partial Solution 2

from itertools import permutations

N = int(input())
hands = []
tmp = []
totals = [-1]*N
for i in range(N):
    for _ in range(4):
        tmp.append(int(input()))
    hands.append(tmp)
    tmp = []

possible = []
for i in hands:
    perm = permutations(i)
    tmp = []
    for j in list(perm):
        if list(j) not in tmp:
            tmp.append(list(j))
    possible.append(tmp)
    tmp = []

largest = -1
biggest = -1
def f(N, k, index):
    global biggest
    if k > biggest and k < 24 and index == 4:
        biggest = k
    
    if k == 24 and index == 4:
        biggest = 24
        return True
    elif index == 4:
        return False
    elif k < 0:
        return False
    else:
        f(N, k+N[index], index+1)
        f(N, k-N[index], index+1)
        f(N, k*N[index], index+1)
        if k % N[index] == 0:
           f(N, int(k/N[index]), index+1)

for i in possible:
    for j in i:
       f(j, j[0], 1)
       if biggest > largest:
           largest = biggest
       biggest = -1
    print(largest)
    largest = -1
