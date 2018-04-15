# https://dmoj.ca/problem/ccc08j2
# 04/15/2018

prac = ["A", "B", "C", "D", "E"]
while True:
    but = int(input())
    num_times = int(input())

    if but == 1:
        for i in range(num_times):
            tmp = prac.pop(0)
            prac.append(tmp)
    if but == 2:
        for i in range(num_times):
            tmp = prac.pop()
            prac = [tmp] + prac
    if but == 3:
        for i in range(num_times):
            tmp = prac[0]
            prac[0] = prac[1]
            prac[1] = tmp
    elif but == 4:
        print(" ".join(prac))
        break
