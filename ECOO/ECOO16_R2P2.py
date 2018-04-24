# https://dmoj.ca/problem/ecoo16r2p2
# 04/20/2018
# ----------------------------------
# Finished Encoding & Decoding.
# Now must finish how to
# convert base 10 to 26
# ----------------------------------

#encode
letters = "abcdefghijklmnopqrstuvwxyz"


key = int(input()) #5
word = input().split()
num_words = len(word)
hold = ''

d = num_words // 26
if d != 0:
    hold += str(d)
    for i in range(d):
        
    
#word = "agddecdhputthelimeinthecoconut"
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
'''
#decode

key = 13
word = 'ccxupnkiivspyqdtlsshwc'
tmp = ''

for i in range(len(word)-1, -1, -1):
    total = 0
    for j in range(0, len(tmp)):
        total += letters.index(tmp[j])
    num_rotate = ((total+key)%26)
    
    current = ((letters.index(word[i])-num_rotate)%26)
    tmp += letters[current]

print(tmp[::-1])
'''
