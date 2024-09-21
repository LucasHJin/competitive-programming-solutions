#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    int abc = 0;
    for (int i=0; i<=n-3; i++) {
        if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') {
            abc++;
        }
    }

    
    for (int i=0; i<q; i++) {
        int x;
        char c;
        cin >> x >> c;
        x--;
        //remove before 
        for (int j=max(0, x-2); j<=min((int)s.size()-3, x); j++) { //only check changed interval
            if (s[j]=='A' && s[j+1]=='B' && s[j+2]=='C') {
                abc--;
            }
        }
        s[x] = c;
        //remove after
        for (int j=max(0, x-2); j<=min((int)s.size()-3, x); j++) { 
            if (s[j]=='A' && s[j+1]=='B' && s[j+2]=='C') {
                abc++;
            }
        }
        cout << abc << endl;
    }

    return 0;
}

