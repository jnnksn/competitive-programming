# https://dmoj.ca/problem/ccc14s3
# 06/30/2018
# -------------------------------
# The Algorithm:
# It it is a very simple process:
# From the mountain you can go down to the lake, or the branch.
# From the branch, you can go down to the lake
# 
# So, you iterate through the cars in the mountain, if it obeys 1, 2, 3, ..., N, then you can add it to the lake
# e.g. lake = [1] and the next car is 2, thus you can add it. If the next car is 3, you cannot since 1 and 3 are not adjacent
# Then, if it does not obey, then add it to the branch.
# What I initially overlooked was that you can go branch --> lake while there are still cars in the mountain.
# So, before you check the two cases above, run a while loop to add the last element of the branch to the lake as long as
# it obeys 1, 2, 3, ..., N
# 
# Then iterate through the cars in the branch, if it obeys 1, 2, 3, ..., N then append to lake
#
# Lastly, we have a comparison list that was made before, (sorted list of all the cars) and we compare the order of the cars
# in the lake to the list. If both are equal then "Y", else "N".
# Note that this is unnecessary and you can just check if length of lake is equal to N.
# -------------------------------

T = int(input())
for _ in range(T):
    mount = []
    branch = []
    lake = []
    M = int(input())
    for i in range(M):
        x = int(input())
        mount.append(x)
    want = [i for i in mount]
    want.sort()
    
    
    for i in range(len(mount)-1, -1, -1):
        while(len(branch) > 0 and branch[-1]-1 == len(lake)):
            lake.append(branch[-1])
            del branch[-1]
        if len(lake) == mount[i]-1:
            lake.append(mount[i])
        else:
            branch.append(mount[i])

    
    for i in range(len(branch)-1, -1, -1):
        if len(lake) == branch[i]-1:
            lake.append(branch[i])
                
    if lake == want:
        print("Y")
    else:
        print("N")
