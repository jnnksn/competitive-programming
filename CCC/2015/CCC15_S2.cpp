// https://dmoj.ca/problem/ccc15s2
// 07/05/2018
// -----------------------------------
// Note to self: 
// I was quite confused on what was going on!
// Remember to read problem statement > once.
// I ended up reading the editorial to figure out what
// I wasn't understanding, and when I figured it out, I went
// back to the problem statement, and what I missed was right
// in the question! The editorial solution on DMOJ is great,
// and I couldn't get it out of my head, so here it is...
//
// The Algorithm:
// This will be a greedy algorithm since we just want to take a maximum amount,
// and there is nothing tricky. Just give the jersey to the first person that
// wants it. 
// nuff said. You can read the rest of the code to figure it out.
// -----------------------------------

#include <iostream>
using namespace std;

const int MAXJA = 1000001;

int j[MAXJA];

int J, A, x, ans=0;
char t;

int main() {
	cin >> J >> A;
	for (int i = 1; i <= J; ++i) {
		cin >> t;
		if (t == 'S') j[i] = 0;
		else if (t == 'M') j[i] = 1;
		else if (t == 'L') j[i] = 2;
	}

	for (int i = 1; i <= A; ++i) {
		cin >> t >> x;
		int n;
		if (t == 'S') n = 0;
		else if (t == 'M') n = 1;
		else if (t == 'L') n = 2;
		if (j[x] >= n) {ans++; j[x] = -1;}
	}

	cout << ans << "\n";

}
