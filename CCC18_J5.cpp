#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// var declaration
vector<int> adj[10001];
int dist[10001], N, numPage, pageReach;
bool visited[10001] = {false};
vector<int> hasZero;


bool visitAll() {
  for (int i = 1; i < N+1; i++) {
    if (visited[i] == false) return false;
  }
  return true;
}


int main() {
  cin >> N;
  
  for (int i = 1; i < N + 1; i++) {
    cin >> numPage;
    if (numPage == 0) {
      // push back page number with 0
      hasZero.push_back(i);
    }
    for (int j = 0; j < numPage; j++) {
      cin >> pageReach;
      adj[i].push_back(pageReach);
    }
    
  }
  
 // get_input();
  
  queue<int> q;
  q.push(1);
  visited[1] = true;
  dist[1] = 0;
  // SAME SOMETHING WRONG WITH DIST INPUT OR SOMETHING
  
  /*
  while (!q.empty()) {
    int s = q.front(); q.pop();
    // process node s
    for (auto u : adj[s]) {
      if (visited[u]) continue;
      visited[u] = true;
      dist[u] = dist[s] + 1;
      q.push(u);
    }
  }
  */
  
  while (!q.empty()) {
    int s = q.front(); q.pop();
    // process node s
    for (int u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        dist[u] = dist[s] + 1;
        q.push(u);
    }
  }
  
  if (visitAll()) {
    cout << "Y" << "\n";
  } else {
    cout << "N" << "\n";
  }
  
  
  int smallest = N;
  for (auto u : hasZero) {
    if (dist[u] < smallest && visited[u]) {
      smallest = dist[u];
    }
  }
  
  cout << smallest+1;
  
  return 0;
}
