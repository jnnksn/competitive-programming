// https://dmoj.ca/problem/ccc12s2
// 08/24/2018
// -------------------------------------------
// The Algorithm:
// Take in input as a string, then iterate through the string starting from the second letter (first roman letter)
// and increase by 2 each time. We add or substract based on the roman letter after the one we are currently evaluating,
// that is, if the roman letter after this one is greater, we subtract the current combination from the total.
// -------------------------------------------

#include <bits/stdc++.h>
using namespace std;

map<char, int> roman;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;
	string phrase; cin >> phrase;
	int total = 0;
	for (int i = 1; i < phrase.length()-2; i+=2) {
		int val = roman[phrase[i]];
		int nval = roman[phrase[i+2]];
		if (val < nval) total -= (val*(phrase[i-1]-'0'));
		else total += (val*(phrase[i-1]-'0'));
	}
	total += (roman[phrase[phrase.length()-1]] * (phrase[phrase.length()-2] - '0'));
	cout << total << "\n";
}
