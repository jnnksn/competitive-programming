// https://dmoj.ca/problem/ccc18j3

using namespace std;
int distances[5];
int tmp;
int main() {
    distances[0] = 0;
    for (int i = 1; i < 5; i++) {
        cin >> tmp;
        distances[i] = distances[i-1] + tmp;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << abs(distances[i] - distances[j]) << " ";
       }
       cout << "\n";
   }
}
