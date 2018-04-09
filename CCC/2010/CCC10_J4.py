# https://dmoj.ca/problem/ccc10j4
# 04/09/2018

while True:
    temps = input().split()
    if temps[0] == "0":
        break
    temps.pop(0)
    if len(temps) == 1:
        print(0)
        continue
    temps = [int(i) for i in temps]
    cycles = [temps[i] - temps[i-1] for i in range(1, len(temps))]
    
    curr = []
    cont = 0
    d = []
    f = 0
    for i in range(len(cycles)):
        curr.append(cycles[i])
        works = True
        for j in range(i+1, len(cycles)):
            if cycles[j] != curr[cont]:
                works = False
                break
            cont += 1
          
            if cont == len(curr):
                cont = 0
        if works:
            f = len(curr)
            break

    if f == 0:
        print(1)
    else:
        print(f)
