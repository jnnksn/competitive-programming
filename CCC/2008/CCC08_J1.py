# https://dmoj.ca/problem/ccc08j1
# 04/15/2018

weight = float(input())
height = float(input())

BMI = weight / (height*height)

if BMI > 25:
    print("Overweight")
elif BMI >= 18.5 and BMI <= 25.0:
    print("Normal weight")
else:
    print("Underweight")
