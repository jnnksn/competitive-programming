# https://dmoj.ca/problem/ccc18s1
# -----------------------------------------------
# Okay, was it just me, or was the problem statement difficult to understand? LOL
#
# The Algorithm:
# The idea is that we are given the "positions" of the N villages.
# this is sneaky, since instead of giving us the villages in their proper order, they randomly give us their positions.
# Luckily, positions move in ascending order (obviously), thus we sort the collected values and that is our position.
# We can think of them as being displayed along an x-axis on a cartesian grid.
# 
# The size of a village is all the points closest to that village.
# for example, from our sample input:
# 0 4 10 15 16 (ascending order)
# we then put in the midpoints between each village denoted as (x)
# 0 (2) 4 (3) 10 (2.5) 15 (0.5) 16
# notice that the midpoints are the halved differences between two adjacent villages.
# The size is defined as the range of all points closest to village X
# thus, for example:
# 0 (2) 4 ( 3)
# It is stated that all points equally close to both adjacent villages and closer to the village are in its neighborhood.
# thus from a range of 2 plus a range of 3, we are given 5 for the neighborhood size of village 4.
# Remembering that rightmost and leftmost villages have infinite neighborhoods, we look at 4, 10, and 15.
# Following the concept above, we arrive with village sizes of 5.0, 5.5, and lastly 3.0.
# we then output the minimum of these sizes.
#
# PLEASE NOTE:
# Numbers used in this problem are BIG, and some languages output BIG numbers in scientific notation which does not
# match desired output. Despite being the same value, you will recieve a WRONG ANSWER since they are looking for EXACT outputs.
#
# I also have no clue why they defined neighborhood sizes as:
# "the difference between the minimum (leftmost) point in its 
# neighbourhood and the maximum (rightmost) point in its neighbourhood."
# I had to make sense of the sample input and explanation of the sample output to work this out. I felt that the wording
# was quite... off for this problem.
# -----------------------------------------------

N = int(input())
villages = []
differences = []
sizes = []
for i in range(N):
  villages.append(int(input()))

villages.sort()

for x in range(1, len(villages)):
  c = villages[x] - villages[x-1]
  differences.append(c/2)

for z in range(len(differences)-1):
  sizes.append(differences[z] + differences[z+1])

print(min(sizes))
