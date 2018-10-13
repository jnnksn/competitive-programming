// https://dmoj.ca/problem/ccc01s1
// 10/13/2018
// -------------------------------
// It's been a while since I've solved a CCC
// problem, so here it is... I'll admit that 
// my implementation skills in c++ aren't that great :/
// -------------------------------
#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> hand;
map<char, int> convert = {{'A', 4}, {'K', 3}, {'Q', 2}, {'J', 1}};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	hand['C'].push_back(-1);
	hand['D'].push_back(-1);
	hand['H'].push_back(-1);
	hand['S'].push_back(-1);
	string phrase; getline(cin, phrase);
	char curr;
	for (int i = 0; i < phrase.length(); i++) {
		char q = phrase[i];
		if (hand.count(q)) {
			curr = q;
		} else {
			hand[curr].push_back(q);
		}
	}
	cout << "Cards Dealt              Points\n";
	int total = 0;
	for (auto i : hand) {
		int len = 0;
		if (i.first == 'C') {
			cout << "Clubs ";
			len = 6;
		} else if (i.first == 'D') {
			cout << "Diamonds ";
			len = 9;
		} else if (i.first == 'H') {
			cout << "Hearts ";
			len = 7;
		} else {
			cout << "Spades ";
			len = 7;
		}
		int sum = 0;
		if (i.second.size()-1 == 0) sum = 3;
		else if (i.second.size()-1 == 1) sum = 2;
		else if (i.second.size()-1 == 2) sum = 1;
		for (auto j : i.second) {
			if (j == -1) continue;
			cout << j << " ";
			len+=2;
			if (isalpha(j) && j != 'T') {
				sum += convert[j];
			}
		}
		for (int j = 1; j <= (31 - len-1); j++) cout << " ";
		cout << sum << "\n";
		total += sum;
	}
	string output = to_string(total);
	for (int i = 1; i <= (31 - 6 - output.length()); i++) {
		cout << " ";
	}
	cout << "Total " << output << "\n";
}
