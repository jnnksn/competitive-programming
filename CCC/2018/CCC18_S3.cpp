// https://dmoj.ca/problem/ccc18s3
// 05/11/2018
// -------------------------------
// The corner case where the
// robot spawns next to a camera
// was the major problem here.
// I honestly thought I accounted
// for that, but turns out I
// didn't. 
// 
// Another thing to keep in mind
// is that on a 2D grid, visiting
// once while traversing may not
// give lowest amount of steps.
// Hence, you can only move to 
// a spot on the grid if the 
// current move + 1 is less than
// the spot it is moving to.
// -------------------------------

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int rows, cols, dist[101][101], start_row, start_col, x, y;
char grid[101][101];
bool blocked[101][101];
string tmp;
vector<int> C1, C2;
queue<pair<int, int>> q;
pair<int, int> hold;

void BFS() {
    
    dist[start_row][start_col] = 0;
    q.push(make_pair(start_row, start_col));
    if (!blocked[start_row][start_col]) {
        while (!q.empty()) {
            hold = q.front(); q.pop();
            x = hold.first;
            y = hold.second;
            // conv
            if (grid[x][y] == 'U') {
                if (dist[x-1][y] > dist[x][y]) {
                    if (!blocked[x-1][y]) {
                        dist[x-1][y] = dist[x][y];
                        q.push(make_pair(x-1,y));
                    }
                }
                continue;
            } else if (grid[x][y] == 'D') {
                if (dist[x+1][y] > dist[x][y]) {
                    if (!blocked[x+1][y]) {
                        dist[x+1][y] = dist[x][y];
                        q.push(make_pair(x+1,y));
                    }
                }
                continue;
            } else if (grid[x][y] == 'R') {
                if (dist[x][y + 1] > dist[x][y]) {
                    if (!blocked[x][y + 1]) {
                        dist[x][y + 1] = dist[x][y];
                        q.push(make_pair(x,y + 1));
                    }
                }
                continue;
            } else if (grid[x][y] == 'L') {
                if (dist[x][y - 1] > dist[x][y]) {
                    if (!blocked[x][y - 1]) {
                        dist[x][y - 1] = dist[x][y];
                        q.push(make_pair(x,y - 1));
                    }
                }
                continue;
            }
            
            // NOT CONV!!
            if (dist[x - 1][y] > dist[x][y]+1) {
                if (!blocked[x - 1][y]) {
                    dist[x - 1][y] = dist[x][y] + 1;
                    q.push(make_pair(x-1, y));
                }
            }
            
            if (dist[x + 1][y] > dist[x][y]+1) {
                if (!blocked[x + 1][y]) {
                    dist[x + 1][y] = dist[x][y] + 1;
                    q.push(make_pair(x+1, y));
                }
            }
            
            if (dist[x][y - 1] > dist[x][y]+1 ) {
                if (!blocked[x][y - 1]) {
                    dist[x][y - 1] = dist[x][y] + 1;
                    q.push(make_pair(x, y - 1));
                }
            }
            
            if (dist[x][y + 1] > dist[x][y]+1) {
                if (!blocked[x][y + 1]) {
                    dist[x][y + 1] = dist[x][y] + 1;
                    q.push(make_pair(x, y + 1));
                }
            }
            
            
        }
    }
}


int main() {
    // store input in row by col grid
    cin >> rows >> cols;
    
    for (int i = 0; i < rows; ++i) {
        cin >> tmp;
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = tmp[j];
            if (tmp[j] == 'W' || tmp[j] == 'C') blocked[i][j] = true;
            if (tmp[j] == 'C') {
                C1.push_back(i);
                C2.push_back(j);
            }
            if (grid[i][j] == 'S') {
                start_row = i;
                start_col = j;
            }
        }
    }
    
    // Camera Mechanics
    // Remember to set 'S' to
    // true if it is hit by a camera!
    for (int i = 0; i < C1.size(); ++i) {
        for (int j = C1[i]-1; j > -1; --j) {
            if (grid[j][C2[i]] == '.' || grid[j][C2[i]] == 'S') blocked[j][C2[i]] = true;
            else if (grid[j][C2[i]] == 'W') break;
        }
        for (int j = C1[i]+1; j < rows; ++j) {
            if (grid[j][C2[i]] == '.' || grid[j][C2[i]] == 'S') blocked[j][C2[i]] = true;
            else if (grid[j][C2[i]] == 'W') break;
        }
        for (int j = C2[i]-1; j > -1; --j) {
            if (grid[C1[i]][j] == '.' || grid[C1[i]][j] == 'S') blocked[C1[i]][j] = true;
            else if (grid[C1[i]][j] == 'W') break;
        }
        for (int j = C2[i]+1; j < cols; ++j) {
            if (grid[C1[i]][j] == '.' || grid[C1[i]][j] == 'S') blocked[C1[i]][j] = true;
            else if (grid[C1[i]][j] == 'W') break;
        }
    }
    
    
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dist[i][j] = 1e9;
        }
    }
    
    
    BFS();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '.' && dist[i][j] == 1e9) cout << "-1\n";
            else if (grid[i][j] == '.') cout << dist[i][j] << "\n";
        }
    }
    
    
}
