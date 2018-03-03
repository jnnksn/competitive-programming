#include <iostream>
#include <vector>
using namespace std;

int dist, num_clubs, tmp;
vector<int> clubs;
int distances[5281];

void get_input() {
    cin >> dist >> num_clubs;
    for (int x = 0; x < num_clubs; x++) {
        cin >> tmp;
        clubs.push_back(tmp);  
    }
}

void find_dist(int distz) {
    for (int i = 1; i < distz+1; i++) {
        for (int x = 0; x < clubs.size(); x++) {
            if (clubs[x] <= i && (distances[i-clubs[x]]+1) < distances[i]) {
                distances[i] = distances[i-clubs[x]]+1;
            }
        }
    }
}

int main() {
   for (int i = 0; i < 5281; i++) distances[i] = 99999;
   get_input();
   distances[0] = 0;
   find_dist(dist);
   /*
   for (int i = 0; i < 101; i++) {
       if (distances[i] < 99999) cout << distances[i] << "\n";
   }
   */
   if (distances[dist] == 99999) {
       cout << "Roberta acknowledges defeat." << "\n";
   } else {
       cout << "Roberta wins in " << distances[dist] << " strokes.";
   }
}
