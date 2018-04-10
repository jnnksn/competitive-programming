# https://dmoj.ca/problem/ccc16s2
# 04/10/2018

q = int(input())
meh = input()
dmoj = input().split()
dmoj = [int(i) for i in dmoj]
peg = input().split()
peg = [int(i) for i in peg]
dmoj.sort()
peg.sort()

total = 0
def Q1():
    global total
    for i in range(len(dmoj)):
        total += max(peg[i], dmoj[i])
    print(total)

c = len(dmoj)-1

def Q2():
    global total
    for i in range(len(dmoj)):
        total += max(dmoj[i], peg[c-i])
        
    print(total)
if q == 1:
    Q1()
else:
    Q2()
