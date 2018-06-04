// https://dmoj.ca/problem/ccc13s4
// 06/03/2018
// -------------------------------
// BFS that traverses by lesser height. 
// We check visited whether the "greater" height is bigger than
// the "smaller" height, or vice versa. 
// If we can reach the "smaller" height starting from the "greater" height then 'yes'
// Otherwise, start again, but from the "smaller" height.
// if we can reach the "greater" height starting from the "smaller" height then 'no'
// otherwise both can't reach eachother therefore it is unknown.
//
// WOW graph theory is much easier than DP...
// -------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, P, X, Y, BIG, SMALL;
vector<int> adj[1000001], ans[1000001];
bool visited[1000001] = {false};
queue<int> q;
int main() {
    cin >> N >> P;
    for(int i = 0; i < P; ++i) {
        cin >> X >> Y;
        adj[X].push_back(Y);
    }
    
    cin >> BIG >> SMALL;
 
    q.push(BIG);
    
    int visit_once = 0;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            q.push(u);
            visited[u] = true;
        }
        
        if (q.empty() && !visited[SMALL] && visit_once == 0) {
            q.push(SMALL);
            visit_once = 1;
        }
        
    }
    
    if (visited[SMALL] && !visited[BIG]) cout << "yes\n";
    else if (!visited[SMALL] && visited[BIG]) cout << "no\n";
    else cout << "unknown\n";
}
