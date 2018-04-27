# https://dmoj.ca/problem/ecoo15r2p3
# 4/27/2018
# ----------------------------------
# Move all but last disk to second pin
# which is N moves - 1 from the
# N disks given in input.
# move last disk to third pin
# then move N - 1 disks to third pin.
# Thus 2 * (N-1) + 1
# ----------------------------------

for _ in range(10):
    poopOnMe = int(input().split()[0])
    print((2 * (poopOnMe-1)) + 1)
