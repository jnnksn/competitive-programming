# https://dmoj.ca/problem/ccc18s2

numSun = int(input())
firstLast = []
for i in range(numSun):
    k = input()
    c = k.split()
    firstLast.append(c)

table2 = []
works = True
# -1

for _ in range(3):

    for x in range(1, len(firstLast)):
        # loop array in firstLast's array
        for c1 in range(1, len(firstLast[x])):
            # if element is less than one before it
            if int(firstLast[x][c1]) < int(firstLast[x][c1 - 1]):
           
                works = False
    
            if int(firstLast[x][c1]) < int(firstLast[x-1][c1]):
               
                works = False

    if works == False:
        firstLast1 = []
        c = []
        # loop num cycles
        for cycles in range(numSun):
        # grabbing last element of each array to form new one
            for k in range(0, len(firstLast)):
                c.append(firstLast[k][-1])
                firstLast[k].pop()
            firstLast1.append(c)
            c = []
        firstLast = firstLast1
        works = True
    else:
        break
  
lol = ""
for z in range(len(firstLast)):
    for l in range(len(firstLast[z])):
        lol += str(firstLast[z][l]) + " "
    print(lol)
    lol = ""
