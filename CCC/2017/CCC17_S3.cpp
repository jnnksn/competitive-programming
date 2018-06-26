// https://dmoj.ca/problem/ccc17s3
// 06/26/2018
// -------------------------------
// Note to self: Read problems correctly!
// I had the main concept from the start, but reading the problem incorrectly messed me up a bit...
// Also using python seems a bit slow.
//
// The Algorithm:
// We make an array of the maximum height of a wood (4000)
// we record the number of woods that have that length (e.g. Index 400 has value 2 --> 2 woods with height 400)
// There is also a maximum height of 4000 for boards (same concept as wood, but store length of fence)
//
// The idea is that we find distinct combinations of 2 woods to make an unique board. We can use an O(n)^2 approach to do this.
// one loop 1...2000 (i = 1)
// a nested loop i...2000 (j = i)
// j will never be less than i, since we are making UNIQUE combinations of i + j, and if j starts at 0, we can have a repeat of j + i.
// as long as there is more than 1 piece of wood for that height of i and j, we can perform the addition
// the resulting height of (i + j) is added to lengths (i + j), since it is another board of that height thus increasing the length
// to determine how much of the length we increase by, it is the number of times we can perform (i + j), hence we find the minimum
// since given 2 wood of height x and 3 wood of height y, we can only make 2 boards of height x + y, with wood of y leftover.
// We must deal with i == j seperately, since say we have 2 woods of height 5. Using our previous method, we would get 2 boards of
// height 10, but it should be 1 board, thus we divide by 2 in this case to determine how much the length increases at (i * 2). 
//
// We then loop through all lengths, finding the largest length while maintaining a variable to keep track of the number of heights
// that have the same length.
// -------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

int N, l, woods[2001], lengths[4001];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> l;
		woods[l] += 1;
	}
	
	for (int i = 1; i <= 2000;++i) {
		if(woods[i]) {
			for (int j = i; j <= 2000; ++j) {
				if (i == j) lengths[i +j] += woods[i] / 2;
				else if (woods[j] > 0) lengths[i+j] += min(woods[i], woods[j]);
			}
		}
	}

	int MAXl = -1, NUMl = 0;
	for (int i = 1; i <= 4000; ++i) {
		if (lengths[i] > MAXl) {
			MAXl = lengths[i];
			NUMl = 1;
		} else if (lengths[i] == MAXl) {
			NUMl += 1;
		}
	}

	cout << MAXl << " " << NUMl << "\n";

}
