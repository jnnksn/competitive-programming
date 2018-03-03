#https://dmoj.ca/problem/ecoo17r1p2
#WARNING: Very inefficient!
for _ in range(10):
  readLine = ""
  names = []
  # P F G
  scoreTracker = []
  read = False
  N = int(input())
  names.append(input())
  scores = []
  p = []
  f = []
  g = []
  #find = []
  for _ in range(N):
    p.append(0)
    f.append(0)
    g.append(0)
    #find.append(False)
  while readLine != "*":
    readLine = input()
    if readLine[0] != "J":
      if readLine[0] != "*":
        names.append(readLine)
      scores.append(scoreTracker)
      scoreTracker = []
    elif readLine[0] == "J":
      splitted = readLine.split()
      scoreTracker.append(splitted[1:len(splitted)])
  
  
  # P F G
  
  total1 = 0
  total = []
  for i in range(len(names)):
    for x in range(len(scores[i])):
      for c in range(3):
        total1 += int(scores[i][x][c])
        if c == 0:
          p[i] += int(scores[i][x][c])
         
        elif c == 1:
          f[i] += int(scores[i][x][c])
          
        elif c == 2:
          g[i] += int(scores[i][x][c])
          
    total.append(total1)
    total1 = 0
  
  #(scores)
  #print(total)
  #print(p)
  #print(f)
  #print(g)
  
  count1 = 0
  saved = ""
  d = []
  f1 = []
  p1 = []
  g1 = []
  
  for i in range(len(names)):
    if total[i] == max(total):
      saved = names[i]
      count1 += 1
      f1.append(f[i])
      d.append(names[i])
      p1.append(p[i])
      g1.append(g[i])
    else:
      continue
  
  f = list(f1)
  names = list(d)
  p = list(p1)
  g = list(g1)
  
  f1 = []
  d = []
  p1 = []
  g1 = []
  if count1 == 1:
    print(saved)
  else:
    count1 = 0
    saved = ""
    for c in range(len(names)):
      if g[c] == max(g):
        count1 += 1
        saved = names[c]
        f1.append(f[c])
        d.append(names[c])
        p1.append(p[c])
        g1.append(g[c])
      else:
        continue
    f = list(f1)
    names = list(d)
    p = list(p1)
    g = list(g1)
    f1 = []
    d = []
    p1 = []
    g1 = []
    if count1 == 1:
      print(saved)
    else:
      count1 = 0
      saved = ""
      biggestF = 0
      for c in range(len(names)):
        
        if f[c] >= max(f):
          count1 += 1
          saved = names[c]
          f1.append(f[c])
          d.append(names[c])
          p1.append(p[c])
          g1.append(g[c])
        else:
          continue
      f = list(f1)
      names = list(d)
      p = list(p1)
      g = list(g1)
      f1 = []
      d = []
      p1 = []
      g1 =[]
      if count1 == 1:
        print(saved)
      else:
        count1 = 0
        saved = ""
        for c in range(len(names)):
        
          if p[c] == max(p):
            count1 += 1
            saved = names[c]
            f1.append(f[c])
            d.append(names[c])
            p1.append(p[c])
            g1.append(g[c])
          else:
            continue
        f = list(f1)
        names = list(d)
        p = list(p1)
        g = list(g1)
        if count1 == 1:
          print(saved)
        else:
              print(','.join(names))
