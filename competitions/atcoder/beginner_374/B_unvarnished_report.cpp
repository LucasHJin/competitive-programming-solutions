#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    int l = min(s.length(), t.length());
    int m = 0;
    for (int i=0; i<l; i++) {
        if (s[i] != t[i]) {
            m=i+1;
            break;
        }
    }
    if (m==0) {
        if (s.length() != t.length()) {
            cout << l+1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << m << endl;
    }

    return 0;
}
