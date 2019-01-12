N = int(input())
stones = [int(i) for i in input().split()]

dp = [2e9 for i in range(N)]
dp[0] = 0
for i in range(N):
    if i+1 < N: 
        dp[i+1] = min(abs(stones[i]-stones[i+1])+dp[i], dp[i+1])
    if i+2 < N: 
        dp[i+2] = min(abs(stones[i]-stones[i+2])+dp[i], dp[i+2])
print(dp[N-1])
