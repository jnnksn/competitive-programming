# https://dmoj.ca/problem/ccc16j1
# 04/13/2018

w = 0
for _ in range(6):
    tmp = input()
    if tmp == "W":
        w += 1


if w >= 5:
    print(1)
elif w == 3 or w == 4:
    print(2)
elif w == 1 or w == 2:
    print(3)
else:
    print(-1)

