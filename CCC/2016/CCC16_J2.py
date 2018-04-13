# https://dmoj.ca/problem/ccc16j2
# 04/13/2018

square = []
for i in range(4):
    tmp = input().split()
    tmp = [int(i) for i in tmp]
    square.append(tmp)

num_true = 0
check_total = 0
track = 0
first = True
for i in square:
    for j in i:
        if first:
            check_total += j
        track += j
    if track == check_total:
        num_true += 1
    first = False
    track = 0


for i in range(4):
    for j in range(4):
        track += square[j][i]
    if track == check_total:
        num_true += 1
    track = 0

if num_true == 8:
    print("magic")
else:
    print("not magic")
