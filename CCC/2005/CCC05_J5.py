# https://dmoj.ca/problem/ccc05j5
# 04/17/2018
# -------------------------------
# Reminder: length of string must be greater than or equal to 3
# when checking, otherwise program throws out of index error!
# -------------------------------


# A-word
# A
# B + monkey language word + S
def A_word(a):
    if a == "A":
        return True
    elif len(a) >= 3 and a[0] == "B" and M_word(a[1:-1]) and a[-1] == "S":
        return True
    else:
        return False

# Monkey Language Word:
# A-word
# A-word + N + monkeyword
def M_word(x):
    if A_word(x):
        return True
    else:
        tmp = ""
        for i in range(len(x)):
            tmp += x[i]
            if len(x) >= 3 and A_word(tmp) and x[i+1] == "N" and M_word(x[i+2:]):
                return True

while True:
    d = input()
    if d == "X":
        break
    
    if M_word(d):
        print("YES")
    else:
        print("NO")
