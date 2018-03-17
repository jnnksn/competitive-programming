# https://dmoj.ca/problem/ccc16j3

word = input()
length = 0
totals = []
track = []
def find_pal(N):
    
    if N[::-1] == N:
        totals.append(len(N))
        return len(N)
    else:
        if N not in track:
            track.append(N)
            find_pal(N[0:-1])
            find_pal(N[1:])

find_pal(word)
print(max(totals))
