// https://dmoj.ca/problem/dmpg18b6
// 04/30/2018

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, tmp;
vector<int> widths, temp;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        widths.push_back(tmp);
    }
    sort(widths.begin(), widths.end());
    temp.push_back(widths[0]);
    for (auto i : widths) {
        if (i - temp[temp.size()-1] >= K) temp.push_back(i);
    }
    cout << temp.size() << "\n";
}
