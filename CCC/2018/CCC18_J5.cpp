// https://dmoj.ca/problem/ccc18j5
// 05/06/2018
// -------------------------------
// Learned that you can declare vectors
// with predefined size!
// One thing to remember is that when
// checking for smallest distance,
// remember that the page you are checking
// is an ending page AND can be visited.
// -------------------------------

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N_page, dist[10001], M, tmp, SMALL = 100001;
bool visited[10001]; // default is false
vector<int> adj[10001];
queue<int> q;

int main() {
    // INPUT
    cin >> N_page;
    for (int i = 1; i < N_page+1; ++i) {
        cin >> M;
        for (int j = 0; j < M; ++j) {
            cin >> tmp;
            adj[i].push_back(tmp);
        }
    }
    
    // BFS SETUP
    visited[1] = true;
    dist[1] = 1;
    q.push(1);
    
    // BFS
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        if (dist[s] < SMALL && adj[s].empty() && visited[s]) SMALL = dist[s];
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);
        }
    }
    
    // Final Statements
    bool reachable = true;
    for (int i = 1; i < N_page+1; ++i) {
        if (!visited[i]) {
            reachable = false;
            cout << "N\n";
            break;
        }
    }
    if (reachable) cout << "Y\n";
    cout << SMALL << "\n";
}

