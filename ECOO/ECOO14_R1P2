// https://dmoj.ca/problem/ecoo14r1p2
// ugly code is good code.

#include <iostream>
#include <string>
#include <map>
using namespace std;

string in_one, in_two, builder="", tmp, saved;
int shift = 0, track = 0;
bool found = false, not_found = true;

string  builder1 = "", tmp1, saved1;
int shift1 = 0, track1 = 0;
bool found1 = false, not_found1 = true;

map <string, string> dict;
int main() {
    
    dict[" "] = "00100000";
    dict["A"] = "01000001";
    dict["B"] = "01000010";
    dict["C"] = "01000011";
    dict["D"] = "01000100";
    dict["E"] = "01000101";
    dict["F"] = "01000110";
    dict["G"] = "01000111";
    dict["H"] = "01001000";
    dict["I"] = "01001001";
    dict["J"] = "01001010";
    dict["K"] = "01001011";
    dict["L"] = "01001100";
    dict["M"] = "01001101";
    dict["N"] = "01001110";
    dict["O"] = "01001111";
    dict["P"] = "01010000";
    dict["Q"] = "01010001";
    dict["R"] = "01010010";
    dict["S"] = "01010011";
    dict["T"] = "01010100";
    dict["U"] = "01010101";
    dict["V"] = "01010110";
    dict["W"] = "01010111";
    dict["X"] = "01011000";
    dict["Y"] = "01011001";
    dict["Z"] = "01011010";
      
    for (int i = 0; i < 10; i++) {
        cin >> in_one >> in_two;
        for (int i = 0; i < in_one.length(); i++) {
            if (in_one[i] == 'G') in_one[i] = '0';
            if (in_one[i] == 'C') in_one[i] = '0';
            if (in_one[i] == 'T') in_one[i] = '1';
            if (in_one[i] == 'A') in_one[i] = '1';
            
            if (in_two[i] == 'G') in_two[i] = '1';
            if (in_two[i] == 'C') in_two[i] = '1';
            if (in_two[i] == 'T') in_two[i] = '0';
            if (in_two[i] == 'A') in_two[i] = '0';
        }
        
        while(not_found && not_found1) {
            
            for (int i = shift; i < in_one.length(); i++) {
                
                track += 1;
                tmp += in_one[i];
                if (track == 8) {
                    
                    for (auto const& x : dict) {
                        if (x.second == tmp) {
                            found = true;
                            saved = x.first;
                        }
                    }
                    if (found == true) {
                        
                        builder += saved;
                     
                    } else {
                       
                        shift += 1;
                        builder = "";
                        tmp = "";
                        track = 0;
                        found = false;
                        break;
                    }
                    tmp = "";
                    track = 0;
                    found = false;
                }
                if (i == in_one.length() - 1) {
                    not_found = false;
                 
                }
            }
            
            
            
            for (int i = shift1; i < in_two.length(); i++) {
                    
                track1 += 1;
                tmp1 += in_two[i];
                if (track1 == 8) {
                   
                    for (auto const& x : dict) {
                        if (x.second == tmp1) {
                            found1 = true;
                            saved1 = x.first;
                        }
                    }
                    if (found1 == true) {
                        builder1 += saved1;
                        
                    } else {
                       
                        shift1 += 1;
                        builder1 = "";
                        tmp1 = "";
                        track1 = 0;
                        found1 = false;
                        break;
                    }
                    tmp1 = "";
                    track1 = 0;
                    found1 = false;
                }
                if (i == in_two.length() - 1) {
                    not_found1 = false;
                 
                }
            }
            
        }
        
        if (not_found == false) {
            if (builder == " R S T") cout << "Q R S T" << "\n";
            else cout << builder << "\n";
        }
        else if(not_found1 == false) cout << builder1 << "\n";
        
        not_found1 = true;
        not_found = true;
        builder = "";
        builder1 = "";
        shift1 = 0;
        shift = 0;
        track = 0;
        track1 = 0;
        found = false;
        found1 = false;
    }
}
