# https://dmoj.ca/problem/dwite09c6p4
# 04/29/2018

for _ in range(5):
    amount = int(input())
    n = int(input())
    coins = []
    for _ in range(n):
        coins.append(int(input()))

    visited = [9999] * 101

    def find(N, U):
        if U < visited[N]:
            visited[N] = U
        elif U > visited[N]:
            return
            
        if N >= amount:
            return
        else:
            for i in coins:
                find(N+i, U+1)

    find(0, 0)
    print(visited[amount])

