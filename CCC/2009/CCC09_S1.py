# https://dmoj.ca/problem/ccc09s1
# 03/29/2018

a = int(input())
b = int(input())

total = 0
squared = []
last = round(b**(1./2.))

for i in range(1, last+1):
    if i**2 >= a and i**2 <= b:
        squared.append(i**2)
#idk just loop to last+1.... prob don't need to loop that much :(
for x in range(1, last+1):
    if x**3 in squared:
        total += 1
        
print(total)


            
