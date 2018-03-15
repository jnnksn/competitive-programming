# https://dmoj.ca/problem/gfssoc16j3
# 40/100

N = int(input())
for i in range(N):
    k = int(input())
    line = input().split()
    actual = ""
    for lol in line:
        if "." in lol:
            lol = lol.replace(".", "!!!")
        if lol.isupper():
            actual += "!!!" + lol + "!!! "
        else:
            actual += lol + " "
    print(actual)
