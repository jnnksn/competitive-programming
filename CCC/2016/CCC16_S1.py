# https://dmoj.ca/problem/ccc16s1
# 07/05/2018
# -------------------------------
# the idea is to compare by
# number of occurences and length
# if the 2 strings are different length, then
# automatically it should be "N".
# If the number of occurences of a character in the first string
# is less than that of the second, then it automatically fails as well.
# As long as the number of occurences of the second string is <=
# that of the first, and the number of remaining "*" can make up for the missing characters
# then it should pass. 
# -------------------------------

w1 = input()
w2 = input()
visited = []
c = w2.count("*")
works = True
for i in w1:
    if i in visited: continue
    visited.append(i)
    if w1.count(i) == w2.count(i): continue
    if w1.count(i) > w2.count(i) and w2.count(i) + c >= w1.count(i):
        c = w2.count(i) + c - w1.count(i)
    else:
        works = False;
        break;

if len(w1) == len(w2) and works:
    print("A")
else:
    print("N")
        
