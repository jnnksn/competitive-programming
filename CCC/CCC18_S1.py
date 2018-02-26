# https://dmoj.ca/problem/ccc18s1

N = int(input())
villages = []
differences = []
sizes = []
for i in range(N):
  villages.append(int(input()))

villages.sort()

for x in range(1, len(villages)):
  c = villages[x] - villages[x-1]
  differences.append(c/2)

for z in range(len(differences)-1):
  sizes.append(differences[z] + differences[z+1])

print(min(sizes))
