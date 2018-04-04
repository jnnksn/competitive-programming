# https://dmoj.ca/problem/ioi94p1
# 04/03/2018

N = int(input())
rows = []
for _ in range(N):
    tmp = input().split()
    tmp = [int(i) for i in tmp]
    rows.append(tmp)
    

tap = [x[:] for x in rows]
for i in range(N):
    for j in range(len(tap[i])):
        tap[i][j] = -1

found = -1
def tri(total, length, pos):
    global found
    if length >= N:
        if total > found:
            found = total
        return total
    else:
        if total > tap[length][pos]:
            tap[length][pos] = total
            tri(total + rows[length][pos], length+1, pos)
        if length > 0 and total > tap[length][pos+1]:
            tap[length][pos+1] = total
            tri(total + rows[length][pos+1], length+1, pos+1)
tri(0, 0, 0)
print(found)
