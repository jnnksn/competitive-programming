// https://dmoj.ca/problem/ccc00j5
// 07/03/2018
// ------------------------------
// The Algorithm is a simple BFS/DFS
// However, implementing this was the hardest thing I've ever done.
// At least I worked on my string manipulation skills in C++ :D
// ------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

const int MAXN = 100;

map<string, vector<string>> adj;
queue<string> q;
vector<string> pages;
int n;
string phrase, plink, S, E;
map<string, bool> visited;

bool solve() {
	visited.clear();

	visited[S] = true;
	q.push(S);
	while(!q.empty()) {
		string a = q.front(); q.pop();
		for (auto u : adj[a]) {
			if (visited[u]) continue;
			visited[u] = true;
			q.push(u);
		}
	}

	return visited[E];

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> plink;
		visited[plink] = false;
		pages.push_back(plink);
		while (true) {
			getline (cin, phrase);
			if (phrase == "</HTML>") break;

			for (int j = 0; j < phrase.length(); ++j) {
				if (j+2 < phrase.length()-1 && phrase.substr(j, 2) == "<A") {
					string link = "";
					int x = j+9;
					while (true) {
						if (phrase[x] == '"') break;
						link += phrase[x];
						x++;
					}
					visited[link] = false;
					adj[plink].push_back(link);
				}
			}
		}
	}
	for (int i = 0; i < pages.size(); ++i) {
		for (auto p : adj[pages[i]]) {
			cout << "Link from " << pages[i] << " to " << p << "\n";
		}
	}

	while (true) {
		getline (cin, S);
		if (S == "The End") break;
		getline (cin, E);

		if (solve()) cout << "Can surf from " << S << " to " << E << ".\n";
		else cout << "Can't surf from " << S << " to " << E << ".\n";

	}

}
