# https://dmoj.ca/problem/ccc13s2
# 07/14/2018
# ----------------------------------
# Overall, pretty simple. However, I did
# get stumped by one test case! It is basically
# where all cars will pass! It was an obvious
# corner case which I should have seen earlier
# ----------------------------------

W = int(input())
N = int(input())

weights = []

for i in range(N):
    weights.append(int(input()))

spots = []
total = 0
passed=0
for i in range(N):
    total += weights[i]
    if total > W:
        passed += len(spots)
        break
    spots.append(weights[i])
    if len(spots) == 4:
        total -= spots[0]
        passed+=1
        del spots[0]
    # this is for when all cars will pass
    if i == N-1:
        passed += len(spots)
        

print(passed)
