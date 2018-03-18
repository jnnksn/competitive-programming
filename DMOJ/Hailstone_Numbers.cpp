// https://dmoj.ca/problem/hailstone
// 3/18/2018

#include <iostream>
using namespace std;

int N, counts = 0;

int main() {
   cin >> N;
   while (N > 1) {
       if (N % 2 == 0) N /= 2;
       else N = N * 3 + 1;
       counts += 1;
   }
   cout << counts;
}
