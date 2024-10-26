#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    bool a = false;
    for (int i=0; i<3; i++) {
        if (s[i]=='A') {
            a = true;
            break;
        }
    }
    bool b = false;
    for (int i=0; i<3; i++) {
        if (s[i]=='B') {
            b = true;
            break;
        }
    }
    bool c = false;
    for (int i=0; i<3; i++) {
        if (s[i]=='C') {
            c = true;
            break;
        }
    }
    if (a and b and c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
