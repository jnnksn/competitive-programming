# https://dmoj.ca/problem/cco12p1
# 04/05/2018
# 3/5 marks
# ===============================
# TLE with python... I probably
# should have used C++ :(
# ===============================

n_operations = int(input())
num_dig = int(input())
dig = []
for _ in range(num_dig):
    dig.append(int(input()))

V = int(input())
targets = []
find = []
for _ in range(V):
    targets.append(int(input()))
    find.append(-1)
    
lol = max(targets)
hold = []

def find_num(N, maxi):
    if N in targets and maxi == 0:
       c = targets.index(N)
       find[c] = 1
       return 0
    elif maxi < 0:
        return 0
    else:
        if [N, maxi] not in hold:
            hold.append([N, maxi])
            for i in dig:
                if N*i <= lol:
                    find_num(N * i, maxi - 1)
                if N+i <= lol:
                    find_num(N + i, maxi - 1)
       

for i in dig:
    find_num(i, n_operations)

for i in find:
    if i == -1:
        print("N")
    else:
        print("Y")
