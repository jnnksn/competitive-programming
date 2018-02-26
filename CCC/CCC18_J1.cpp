#include <iostream>
using namespace std;
int main() {
    int a,b,c,d;
    bool works;
    cin >> a >> b >> c >> d;
    
    if (a == 8 || a == 9) {
        if (d == 8 || d == 9) {
            if (b == c) {
                works = true;
            } else {
                works = false;
            }
        } else {
            works = false;
        }
    } else {
        works = false;
    }
    
    if (works) {
        cout << "ignore" << "\n";
    } else {
        cout << "answer" << "\n";
    }
}
