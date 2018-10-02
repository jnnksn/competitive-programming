# https://dmoj.ca/problem/ccc13j3

s = int(input())+1
tmp = str(s)
good = 0
while True:
    for i in tmp:
        if tmp.count(i) == 1:
            good += 1
    if good == len(tmp):
        break
    else:
        good = 0
    s += 1
    tmp = str(s)
    
print(tmp)
