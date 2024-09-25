#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        vector<string> words(3);
        cin >> words[0] >> words[1] >> words[2];
        
        bool good = true;
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (j!=k) {
                    if (words[j].find(words[k]) == 0) {
                        good = false;
                    }
                    //rfind -> last occurence of substring from end of string, returns starting position (first ind of substring)
                    if (words[j].length() >= words[k].length() and words[j].rfind(words[k]) == words[j].length()-words[k].length()) {
                        good = false;
                    }
                }
            }
            if (!good) {
                break;
            }
        }
        if (good) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}

