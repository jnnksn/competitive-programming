# http://codeforces.com/contest/1008/problem/A
# 07/13/2018

s = input()
vowels =  ["a", "o", "u", "i", "e"]
works = True
for i in range(len(s)):
    if s[i] not in vowels and s[i] != "n" and i <= len(s)-2:
        if s[i+1] not in vowels:
            works = False
        continue
    elif i == len(s)-1:
        if s[i] not in vowels and s[i] != "n":
            works = False

if works:
    print("YES")
else:
    print("NO")
