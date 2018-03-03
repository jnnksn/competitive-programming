# https://dmoj.ca/problem/ecoo17r2p1

rules = []
floors = []
collectionString = ""
saveFloor = []

def get_input():
  global N
  global M
  grabLine = input().split()
  N = int(grabLine[0])
  M = int(grabLine[1])
  
  for i in range(4):
    rules.append(input().split())
  floors.append(input())
  asterik = input()


def rule_find():
  global collectionString
  # still have to include M (NUM FLOORS)
  for x in range(M-1):
    for i in range(N):
      for j in range(4):
        if i == 0:
          if floors[x][-1] == rules[j][0][0] and floors[x][i+1] == rules[j][0][1]:
            collectionString += rules[j][1]
        elif i == N-1:
          if floors[x][i-1] == rules[j][0][0] and floors[x][0] == rules[j][0][1]:
            collectionString += rules[j][1]
        else:
          if floors[x][i-1] == rules[j][0][0] and floors[x][i+1] == rules[j][0][1]:
            collectionString += rules[j][1]
    floors.append(collectionString)
    collectionString = ""

for i in range(10):
  get_input()
  rule_find()
  saveFloor.append(floors[-1])
  floors = []
  rules = []
  
for i in range(len(saveFloor)):
  print(saveFloor[i])
