# Initialize Variables
adj = [0] # 0 is not significant. Just so we can count from 1.
queue = []
visited = [False] * 10001
dist = [0] * 10001
SMALL = 10001

# Input
N_page = int(input());
for _ in range(N_page):
    tmp = [int(i) for i in input().split()]
    adj.append(tmp[1:])

# BFS SETUP
visited[1] = True;
queue.append(1)
dist[1] = 1

# BFS
while (len(queue) > 0):
    s = queue.pop(0)
    
    if dist[s] < SMALL and len(adj[s]) == 0 and visited[s]: SMALL = dist[s]
    for i in adj[s]:
        if visited[i]: continue 
        visited[i] = True
        dist[i] = dist[s] + 1
        queue.append(i)

# Final Statements
reachable = True
for i in range(1, N_page+1):
    if not visited[i]:
        reachable = False;
        print("N")
        break

if reachable: print("Y")
print(SMALL)
