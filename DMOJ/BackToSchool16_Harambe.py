# https://dmoj.ca/problem/bts16p1
# 3/30/2018

line = input()
up = 0
low = 0
for i in line:
    if i != " " and i.upper() == i:
        up += 1
    elif i != " " and i.upper() != i:
        low += 1
str = ""
if up > low:
    for i in range(len(line)):
        str += line[i].upper()
        
elif up < low:
    for i in range(len(line)):
        str += line[i].lower()
else:
    str = line
print(str)
