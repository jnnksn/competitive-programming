# https://dmoj.ca/problem/ecoo15r1p2
# 4/27/2018
# ----------------------------------
# 75/100 Marks on DMOJ because I suck.
# ----------------------------------

for _ in range(10):
    W = int(input())
    words = input().split()

    for i in words:
        if len(line) > W+1:
            while(len(line) > W):
                print(line[0:W])
                line = line[W:]
            line += i + ' '
        elif current + len(i)+1 <= W+1:
            line += i + ' '
            current += len(i)+1
        else:
            print(line)
            if len(i) > W:
                print(i[0:W])
                line = i[W:] + ' '
                current = len(i[W:]) + 1
            else:
                line = i + ' '
                current = len(i)+1
        if i == words[-1]:
            print(line)
    print('=====')
        

