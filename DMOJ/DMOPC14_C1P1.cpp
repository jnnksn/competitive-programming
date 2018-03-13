// https://dmoj.ca/problem/dmopc14c1p1

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N, tmp;
double index;
vector<int> grades;
int main() {
    grades.push_back(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        grades.push_back(tmp);
    }
    
    sort(grades.begin(), grades.end());
    
    if (N % 2 != 0) {
        index = round(N/2.0);
       
        cout << grades[index];
    } else {
     
        index = N/2;
        double c = (grades[index] + grades[index+1])/2.0;
        cout << round(c);
    }
    
