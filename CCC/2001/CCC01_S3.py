# https://dmoj.ca/problem/ccc01s3
# 06/09/2018
# -------------------------------
# First try:
# Read sample input incorrectly
# Horrible!
# Second try:
# After realizing my mistake for the sample input
# I just had to check what roads to remove to stop going to B
# The Algorithm:
# Starting from A, DFS to B and keep track of all roads used to get to B from A
# Then DFS but each time don't allow one of the roads. See if B is still reachable
# if B is not reachable that means we have stopped all traffic and 
# the road we blocked should be outputted. 
# -------------------------------

alphabet = [0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

adj = [[] for i in range(27)]
visited = [False for i in range(27)] 
ans = []
done = False
a = 0
b = 0

def bombed(x, y):
    global a
    global b
    if x == a and y == b: return True
    if y == a and x == b: return True
    return False

def dfs(s, r):
    global a
    global b
    if (visited[s]): return
    visited[s] = True
    if s == 2 and not done: 
        ans.append(r)
        return
    for u in adj[s]:
        if not bombed(u, s): dfs(u, r + [[s,u]])
table = []
while True:
    road = input()
    if road == "**": break
    table.append(road)
    adj[alphabet.index(road[0])].append(alphabet.index(road[1]))
    adj[alphabet.index(road[1])].append(alphabet.index(road[0]))
    
dfs(1, [])
done = True
count = 0
for i in ans:
    for j in i:
        a = j[0]
        b = j[1]
        visited = [False for i in range(27)]
        dfs(1, [])
        if not visited[2]:
            if alphabet[a] + alphabet[b] not in table:
                print(alphabet[b] + alphabet[a])
            else:
                print(alphabet[a] + alphabet[b])
            count += 1
    
print("There are", count, "disconnecting roads.")
