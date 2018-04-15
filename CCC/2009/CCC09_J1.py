# https://dmoj.ca/problem/ccc09j1
# 4/15/2018

word = "9780921418"
for i in range(3):
    word += input()
total = 0
one_or_three = True
for i in word:
    if one_or_three:
        total += int(i)
        one_or_three = False
    else:
        total += int(i) * 3
        one_or_three = True

print("The 1-3-sum is", total)
