// https://dmoj.ca/problem/ccc14s2
// -------------------------------
// I'm lazy... Nuff said.
// -------------------------------

N = int(input())
X = input().split()
Y = input().split()

BAD = False
for i in X:
    first = X.index(i)
    second = Y.index(i)
    if Y[first] == X[second] and Y[first] != X[first] and Y[second] != X[second]:
        continue
    else:
        BAD = True
        break

if BAD: print("bad")
else: print("good")
