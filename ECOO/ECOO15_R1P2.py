# https://dmoj.ca/problem/ecoo15r1p2
# 4/27/2018
# ----------------------------------
# 70/100 Marks on DMOJ because I suck.
# ----------------------------------

for _ in range(10):
    W = int(input())
    words = input().split()

    current = 0
    line = ''
   
    for i in words:
        if current + len(i)+1 <= W+1:
            line += i + ' '
            current += len(i)+1
        else:
            print(line)
            if len(i) > W:
                print(i[0:W])
                line = i[W:] + ' '
            else:
                line = i + ' '
            current = len(i)+1
        if i == words[-1]:
            print(line)
    print('=====')
