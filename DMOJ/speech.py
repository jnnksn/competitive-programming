# https://dmoj.ca/problem/gfssoc1s2
# 04/13/2018

N = int(input())
words = []
for _ in range(N):
    tmp = input().split()
    words.append(tmp)

line = input().split()

for i in range(len(line)):
    for x in words:
        if line[i] == x[1]:
            line[i] = x[0]
        if line[i][-1] == "." and line[i][:-1] == x[1]:
            line[i] = x[0] + "."

print(" ".join(line))

