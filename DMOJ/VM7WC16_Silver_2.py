# https://dmoj.ca/problem/vmss7wc16c2p2
# 04/29/2018

line = input()
move = [-1] * (len(line))
if line[0] == 'G':
    move[0] = 1
else:
    move[0] = 0
    
Q = int(input())
position = []
for _ in range(Q):
    tmp = [int(i) for i in input().split()]
    position.append(tmp)


for i in range(len(line)):
    if move[i] == -1:
        if line[i] == 'G':
            move[i] = move[i-1] + 1
        else:
            move[i] = move[i-1]

for i in position:
    if i[0] - 1 == -1:
        diff = 0
    else:
        diff = move[i[0]-1]
    print(move[i[1]] - diff)
    
