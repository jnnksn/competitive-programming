// https://dmoj.ca/problem/ccc05j1
// 05/02/2018
/*
Today I have learned about comparing doubles and floats in C++.
It is very.... Wonky... 
An example is the test case where:
A = 38.15 and B = 11.55
B < A returned false. Thus, I resorted to (B-A) < 0.
Remind me to use PYTHON for these type of problems... I spent
way too much time trying to figure this out...
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int day, eve, week;
float totalA = 0, totalB = 0;

int main() {
    cin >> day >> eve >> week;
    if (day > 100) totalA += (day - 100) * 0.25;
    totalA += eve * 0.15;
    totalA += week * 0.2;
    if (day > 250) totalB += (day - 250) * 0.45;
    totalB += eve * 0.35;
    totalB += week * 0.25;
    
    cout << "Plan A costs " << totalA << "\n";
    cout << "Plan B costs " << totalB << "\n";
    if (totalA-totalB < 0) cout << "Plan A is cheapest.\n";
    else if (totalB - totalA < 0) cout << "Plan B is cheapest.\n";
    else cout << "Plan A and B are the same price.\n";
}
