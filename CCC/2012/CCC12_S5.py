# https://dmoj.ca/problem/ccc12s5
# 04/30/2018
# -------------------------------
# Sometimes recursive approach is
# not the answer. I optimized the
# recursive method the best I could.
# However could not think of a way
# to cache, or make it faster. Thus,
# I resorted to an iterative approach
# which let me cache.... Geez I suck.
# -------------------------------

R, C = [int(i) for i in input().split()]
board = []
for i in range(R):
    tmp = []
    for j in range(C):
        tmp.append(0)
    board.append(tmp)

has_cats = [i[:] for i in board]
K = int(input())
for _ in range(K):
    x, y = [int(i) for i in input().split()]
    has_cats[x-1][y-1] = -1

has_cats[0][0] = -1
board[0][0] = 1
for i in range(R):
    for j in range(C):
        if has_cats[i][j] != -1:
            board[i][j] = board[i-1][j] + board[i][j-1]
print(board[R-1][C-1])
