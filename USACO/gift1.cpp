// http://train.usaco.org/usacoprob2?a=pRHTM0r4bV3&S=gift1

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define loop(x,n) for(int x = 0; x < n; x++)
using namespace std;

int NP, money, num_people, split_money, remain;
string person;
vector<string> current;
int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    // One time input
    cin >> NP;
    string friends[NP];
    int bank[NP] {0};
    loop(x, NP) {
        cin >> friends[x];
    }
    
    loop(k, NP) {
        current.clear();
        cin >> person >> money >> num_people;
        string tmp;
        loop(x, num_people) {
            cin >> tmp;
            current.push_back(tmp);
        }
        if (money == 0 || num_people == 0) continue;
        remain = money % num_people;
        if (remain == 0) split_money = money / num_people;
        else split_money = (money - remain) / num_people;
        
        loop(x, NP) {
            if (friends[x] == person) {
                bank[x] += remain;
                bank[x] -= money;
            } 
            loop(c, num_people) {
                if (friends[x] == current[c]) bank[x] += split_money;
            }
        }
        
    }
    loop(lol, NP) {
        cout << friends[lol] << " " << bank[lol] << "\n";
    }
}
