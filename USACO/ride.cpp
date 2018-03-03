# http://train.usaco.org/usacoprob2?a=pRHTM0r4bV3&S=ride

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string a, b;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    int z = 1, y = 1;
    cin >> a >> b;
    for (int x = 0; x < a.length(); x++) z *= a[x] - 'A'+1;
    for (int x = 0; x < b.length(); x++) y *= b[x] - 'A'+1;
    
    
    if (z % 47 == y % 47) cout << "GO" << "\n";
    else cout << "STAY" << "\n";
    return 0;
}

