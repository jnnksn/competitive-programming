// https://dmoj.ca/problem/literatureclub

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int num_sentence, num_words, k_triggers;
int sayori = 0, natsuki = 0, yuri = 0, monika = 0;
vector<int> imGarbage;

int main() {
    cin >> num_sentence >> num_words >> k_triggers;
    string Sayori[k_triggers], Natsuki[k_triggers], Yuri[k_triggers], Monika[k_triggers];
    string poem[num_sentence][num_words];
    for (int i = 0; i < k_triggers; i++) cin >> Sayori[i];
    for (int j = 0; j < k_triggers; j++) cin >> Natsuki[j];
    for (int j = 0; j < k_triggers; j++) cin >> Yuri[j];
    for (int j = 0; j < k_triggers; j++) cin >> Monika[j];
    
    for (int i = 0; i < num_sentence; i++) for (int j = 0; j < num_words; j++) cin >> poem[i][j];
    
    for (int i = 0; i < num_sentence; i++) for (int j = 0; j < num_words; j++) {
        for (int k = 0; k < k_triggers; k++) {
            if (Sayori[k] == poem[i][j]) {
                sayori++;
                Sayori[k] = "abcdefghijklmnop";
            }
            if (Natsuki[k] == poem[i][j]) {
                natsuki++;
                Natsuki[k] = "abcdefghijklmnop";
            }
            if (Yuri[k] == poem[i][j]) {
                yuri++;
                Yuri[k] = "abcdefghijklmnop";
            }
            if (Monika[k] == poem[i][j]) {
                monika++;
                Monika[k] = "abcdefghijklmnop";
            }
        }
    }
    imGarbage.push_back(sayori);
    imGarbage.push_back(natsuki);
    imGarbage.push_back(yuri);
    imGarbage.push_back(monika);
    sort(imGarbage.begin(), imGarbage.end());
    
    if (imGarbage.back() != 0) {
        if (sayori == imGarbage.back()) cout << "Sayori" << "\n";
        if (natsuki == imGarbage.back()) cout << "Natsuki" << "\n";
        if (yuri == imGarbage.back()) cout << "Yuri" << "\n";
        if (monika == imGarbage.back()) cout << "Monika" << "\n";
    } 
}


 
