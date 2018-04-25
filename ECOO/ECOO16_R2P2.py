# https://dmoj.ca/problem/ecoo16r2p2
# 04/25/2018
# ----------------------------------
# Very messy code because I had to
# follow along with Macbeth in 
# English class while doing this!
# 90/100 Marks on DMOJ
# Probably because I made a silly
# mistake while following along :(
# ----------------------------------

letters = "abcdefghijklmnopqrstuvwxyz"



'''
#encode
letters = "abcdefghijklmnopqrstuvwxyz"
'''
for i in range(10):
    key = int(input()) #5
    k = input()
    word = k.split()

    def has_space():
        global word
        global key
        fin1 = 0 + (len(word) // 26)
        fin2 = 0 + (len(word)% 26)
        fin = letters[fin1] + letters[fin2]
        for i in word:
            fin += letters[len(i)]
        word = ''.join(word)
        word = fin + word
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



    def no_space():
        global word
        global key
        word = ''.join(word)
        tmp = ''

        for i in range(len(word)-1, -1, -1):
            total = 0
            for j in range(0, len(tmp)):
                total += letters.index(tmp[j])
            num_rotate = ((total+key)%26)
            
            current = ((letters.index(word[i])-num_rotate)%26)
            tmp += letters[current]
        fin = tmp[::-1]
        num_words = int(str(letters.index(fin[0])) + str(letters.index(fin[1])))
        split = []
        for i in range(2, num_words+2):
            split.append(letters.index(fin[i]))
       
        fin = fin[num_words+2:]
        new_string = ''
        temp = ''
        for i in split:
            for j in fin:
                temp += j
                if len(temp) == i:
                    new_string += temp + ' '
                    break
            temp = ''
            fin = fin[i:]
        print(new_string)

    has_space1 = False
    for i in k:
        if i == ' ':
            has_space1 = True
            break

    if has_space1:
        has_space()
    else:
        no_space()
