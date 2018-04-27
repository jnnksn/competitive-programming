# https://dmoj.ca/problem/ecoo14r2p1
# 4/27/2018
# ----------------------------------
# 90/100 Marks on DMOJ
# ----------------------------------
for _ in range(10):
    possible = ['$1','$2','$5','$10','$50','$100','$1000','$10000','$500000', '$1000000']
    num_mount = [0]*10
    q = 0
    for i in range(9):
        tmp = input()
        if tmp == '?':
            q += 1
        else:
            num_mount[possible.index(tmp)] += 1

    d = []
    for i in range(len(num_mount)):
        num_mount[i] += q
        if num_mount[i] >= 3:
            d.append(possible[i])

    if len(d) == 0:
        print('No Prizes Possible')
    else:
        sorted(d, key=len)
        s = ''
        for i in d:
            s += i + ' '
        print(s)
