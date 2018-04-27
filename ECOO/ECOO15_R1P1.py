# https://dmoj.ca/problem/ecoo15r1p1
# 4/27/2018

for _ in range(10):
    smarties = [0] * 8
    total = 0
    while True:
        tmp = input()
        if tmp == 'end of box':
            break
        else:
            if tmp == 'orange':
                smarties[0] += 1
            elif tmp == 'blue':
                smarties[1] += 1
            elif tmp == 'green':
                smarties[2]+= 1
            elif tmp == 'yellow':
                smarties[3] += 1
            elif tmp == 'pink':
                smarties[4] += 1
            elif tmp == 'violet':
                smarties[5] += 1
            elif tmp == 'brown':
                smarties[6] += 1
            elif tmp == 'red':
                smarties[7] += 1
    total += smarties[7] * 16


    for i in range(len(smarties)-1):
        while smarties[i] > 0:
            smarties[i] -= 7
            total += 13
        
        
    print(total)

