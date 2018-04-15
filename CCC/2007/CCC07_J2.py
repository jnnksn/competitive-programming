# https://dmoj.ca/problem/ccc07j2
# 4/15/2018

short = ["CU", ":-)", ":-(", ";-)", ":-P", "(~.~)", "TA", "CCC", "CUZ", "TY", "YW", "TTYL"]
long = ["see you", "I'm happy", "I'm unhappy", "wink", "stick out my tongue", "sleepy", "totally awesome", "Canadian Computing Competition", "because", "thank-you", "you're welcome", "talk to you later"]

while True:
    word = input()
    if word in short:
        d = short.index(word)
        print(long[d])
    else:
        print(word)
    if word == "TTYL":
        break
