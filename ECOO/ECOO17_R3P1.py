# https://dmoj.ca/problem/ecoo17r3p1
# 05/02/2018

for _ in range(10):
    F, D = [int(i) for i in input().split()]
    total_sold = [0] * F
    total_F = 0
    for j in range(D):
        total = 0
        tmp = [int(i) for i in input().split()]
        for i in range(F):
            total_sold[i] += tmp[i]
            total += tmp[i]
            if j == D-1 and total_sold[i] % 13 == 0:
                temp = total_sold[i] / 13
                total_F += temp
            
        if total % 13 == 0:
            temp = total / 13
            total_F += temp

    print(int(total_F))
