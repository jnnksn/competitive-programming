# https://dmoj.ca/problem/ccc17j2
# 04/04/2018

num = int(input())
num_zero = int(input())

k = str(num)

for _ in range(num_zero):
    k += "0"
    num += int(k)

print(num)

