// https://dmoj.ca/problem/ccc03s3
// 07/04/2018
// -------------------------------------------
// Comments:
// Read question more than once. Could have saved 5+ minutes of confusion
// if I read the problem correctly.
// Little things like > to >= are important and will make you fail testcases!
// 
// The Algorithm:
// Firstly, we store the floor plan in a 2d boolean array called visited. 
// if the spot is open, then its position in the bool array is false.
// if the spot has a wall, then its position is true
// We use this visited array for our BFS, and we never reset the array since
// we need to keep track of rooms/spots we visited throughout the run.
//
// We create a search function that iterates through our visited array
// if the visited spot [i][j] is false, that means it has an open space.
// We then BFS, where we go up, down, left, and right as long as it does not go out of bounds, or has been visited already.
// This will "flood" the room until all boundaries have been reached. Each time we go to a new open spot (node), we add
// it to our counter variable that keeps track of the room's size, and set the spot's position in the visited array to false. 
//
// Remember we are still iterating through the visited array, and we continue to iterate to find all rooms. Note that
// this will never find the same room more than once since after BFSing, all other open spaces are now visited.
// As we visit each room, we append the room's size to a vector.
//
// We then sort the vector, from least to greatest and iterate backwards --> greatest to least.
// As long as the amount of flooring subtracted by each iteration's room size is greater than 0, we can 
// increase the number of rooms covered by 1. We do this until the above condition is false. 
// We are left with a remainder of planks and the number of rooms we can cover from greatest --> least
//
// Lastly we output our findings.
// However, one corner case is where there is only a single room.
// We do not pluralize room(s) when outputting. Thus, this is why I have a different
// output condition for rooms != 1.
// -------------------------------------------

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sqf, r, c, rooms = 0, NO, NT;
string row;
queue<pair<int, int>> q;
bool visited[26][26];

vector<int> fsize;

int solve() {
	int open = 0;
	visited[NO][NT] = true;
	open++;
	q.push({NO, NT});
	while (!q.empty()) {
		pair<int, int> SB = q.front(); q.pop();
		int Y = SB.first, X = SB.second;

		// UP
		if (Y+1 <= r && !visited[Y+1][X]) {
			visited[Y+1][X] = true;
			q.push({Y+1, X});
			open++;
		}

		// DOWN
		if (Y-1 >= 1 && !visited[Y-1][X]) {
			visited[Y-1][X] = true;
			q.push({Y-1, X});
			open++;
		}

		// LEFT
		if (X-1 >= 1 && !visited[Y][X-1]) {
			visited[Y][X-1] = true;
			q.push({Y, X-1});
			open++;
		}

		// RIGHT
		if (X+1 <= c && !visited[Y][X+1]) {
			visited[Y][X+1] = true;
			q.push({Y, X+1});
			open++;
		}
	}

	return open;

}

void search() {
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (!visited[i][j]) {
				NO = i; NT = j;
				fsize.push_back(solve());
			}
		}
	}
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> sqf >> r >> c;
	for (int i = 1; i <= r; ++i) {
		cin >> row;
		for (int j = 0; j < c; ++j) {
			if (row[j] == '.') {
				visited[i][j+1] = false;
			} else {
				visited[i][j+1] = true;
			}

		}
	}

	search();

	sort(fsize.begin(), fsize.end());

	for (int i = fsize.size()-1; i >= 0; --i) {
		if (sqf-fsize[i] >= 0) {
			rooms++;
			sqf -= fsize[i];
		} else break;
	}

	if (rooms != 1) cout << rooms << " rooms, " << sqf << " square metre(s) left over\n";
	else cout << "1 room, " << sqf << " square metre(s) left over\n";

}
