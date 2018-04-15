# https://dmoj.ca/problem/ccc07j3
# 4/15/2018

poss = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000,1000000]

num_eli = int(input())
eli = []
for _ in range(num_eli):
    eli.append(int(input()))
bank = int(input())
total = 0
for i in range(len(poss)):
    if (i+1) not in eli:
        total += poss[i]

av = total/(len(poss) - len(eli))
if av > bank:
    print("no deal")
else:
    print("deal")
