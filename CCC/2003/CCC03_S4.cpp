// https://dmoj.ca/problem/ccc03s4
// 07/31/2018
// --------------------------------------
// My first attempt was a simple bruteforce with memoization using unordered_set --> MLE and TLE (50/100)
//
// The second attempt used the idea that whenever we find a substring, look for any substrings previous to it
// that are the same. We only count that substring if there are no previous substrings that are the same.
// The above algo TLEs (75/100)
//
// The Algorithm:
// Borrowed from: http://mmhs.ca/ccc/2003/S4Substringscl.txt (GOOD EXPLANATION)
// we use a suffix array!
// "a sorted array of all suffixes of a string" (Calvin Liu) <-- note it is lexicographically sorted!
// e.g.
// Given the string "aaaa", the following suffix array is:
// ["a", "aa", "aaa", "aaaa"]
// 
// Every substring of a string is a prefix of a suffix!
// (same idea as before)
// e.g.
// Given the suffix "aaaa", the following prefixes are:
// ["a", "aa", "aaa", "aaaa"] --> LOL
//
// Using the above method we would get a sum of 10 prefixes for the string "aaaa".
// However, there are duplicates! 
// This is where we can find the "Largest Common Prefix"
// This is exactly what the name says, we find the longest prefix string between two strings
// for example, if we are processing a string, we will compare it to an already processed string!
// We find the LCP of the current and processed strings. We then know that the LCP string and all smaller strings
// have already been accounted for, and the only new prefixes are those that are greater than the LCP in the current
// string. 
// e.g.
// Given Suffixes A = "aaaa" and B = "aaa", where A is currently being processed and B has already been processed.
// prefixes A = ["a", "aa", "aaa", "aaaa"] and B = ["a", "aa", "aaa"]
// looking at the two sets of prefixes, we notice that the only different one is "aaaa", and the LCP of A and B
// is "aaa". "aaaa" is after "aaa", thus there is only 1 new substring!
// In other words, # of prefixes in A - # of prefixes in A up to LCP ("aaa") = # of new substrings!
// 4 - 3 = 1
//
// Lastly, we accumulate the number of new substrings, and also add 1 for the case where a substring is "".
// --------------------------------------

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Largest Common Prefix
int LCP(string s, string t) {
	int ln = s.length();
	for (int i = 0; i < ln; ++i) {
		if (s.substr(i, 1) != t.substr(i, 1)) return i;
	}
	return ln;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string str; cin >> str;
		int l = str.length();
		vector<string> s;
		for (int i = 0; i < l; ++i) {
			s.push_back(str.substr(i, l));
		}
		sort(s.begin(), s.end());
		int ans = s[0].length()+1; // account for ""
		for (int i = 1; i < l; ++i) {
			int lcp = LCP(s[i], s[i-1]);
			ans += s[i].length() - lcp;
		}
		cout << ans << "\n";
	}
}
