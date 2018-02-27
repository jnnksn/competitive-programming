# https://dmoj.ca/problem/ecoo16r1p1
for _ in range(10):
  students = []
  passed = 0
  percents = input().split()
  for x in range(len(percents)):
    percents[x] = int(percents[x])
    percents[x] = float(percents[x]/100)
  N_Students = int(input())
  
  for i in range(N_Students):
    tmp = input().split()
    students.append(tmp)
  
  
      
  for x in range(N_Students):
    weight_average = (percents[0] * float(students[x][0])) + (percents[1] * float(students[x][1])) + (percents[2] * float(students[x][2])) + (percents[3] * float(students[x][3]))
  
    if weight_average >= 49.9:
      passed += 1
  
  print(passed)
