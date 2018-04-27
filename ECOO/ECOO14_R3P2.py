# https://dmoj.ca/problem/ecoo14r3p2
# 04/27/2018

N = int(input())
mom = []
daughter = []
for _ in range(N):
    tmp = input().split()
    mom.append(tmp[0])
    daughter.append(tmp[1])

to_find = []
for _ in range(10):
    to_find.append(input())

m = ''
for i in to_find:
    if i in daughter:
        m = mom[daughter.index(i)]
        num_sis = -1
        for x in mom:
            if x == m:
                num_sis += 1
        mm = mom[daughter.index(m)]
        cous_moms = []
        num_cous = 0
        for y in range(len(mom)):
            if mom[y] == mm:
              if daughter[y] != m:
                  cous_moms.append(daughter[y])
        for z in mom:
            if z in cous_moms:
                num_cous += 1
        
    print('Cousins: ' + str(num_cous)+',', 'Sisters: ' + str(num_sis))
