# https://dmoj.ca/problem/ecoo16r2p2
# 04/20/2018
# ----------------------------------
# Not Finished! Have to go get a 
# hair cut. Hopefully I remember 
# to come back!
# ----------------------------------

letters = "abcdefghijklmnopqrstuvwxyz"

key = 5
word = "agddecdhputthelimeinthecoconut"
tmp = ""
for j in range(1,len(word)):
    total = 0
    for i in range(j, len(word)):
        total += letters.index(word[i])
    num_rotate = ((total+key)%26)
    current = ((num_rotate + letters.index(word[j-1]))%26)
    tmp += letters[current]

tmp += letters[(key + letters.index(word[-1]))% 26]
print(tmp)
