# https://dmoj.ca/problem/ccc08s4
# 04/18/2018
# -------------------------------
# DAVID! YOU IDIOT YOU FORGOT
# ABOUT BEDMAS!??!?!?!
# -------------------------------
# 60/100 on DMOJ
# Partial Solution 1

N = int(input())
hands = []
tmp = []
totals = [-1]*N
for i in range(N):
    for _ in range(4):
        tmp.append(int(input()))
    hands.append(tmp)
    tmp = []

def is_24(K, index, num_used, used):
  
    if K > totals[index] and K < 24 and num_used == 4:
        totals[index] = K
    elif K < totals[index] and num_used == 4:
        return False
    
    if K == 24 and num_used == 4:
        totals[index] = K
        return True
    elif K > 24 and num_used == 4:
        return False
    elif num_used == 4:
        return False
    else:
        for i in range(len(hands[index])):
            if i not in used:
                is_24(K+hands[index][i], index, num_used + 1, used + [i])
                is_24(K-hands[index][i], index, num_used + 1, used + [i])
                is_24(K*hands[index][i], index, num_used + 1, used + [i])
                if K % hands[index][i] == 0:
                    is_24(K/hands[index][i], index, num_used + 1, used + [i])

for i in range(len(hands)):
    for j in range(len(hands[i])):
        is_24(hands[i][j], i, 1, [j])

for i in totals:
    print(int(i))
