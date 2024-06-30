#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    for (int w=1; w<n; w++) {
        for (int c=1; c<=w; c++) {
            string cons;
            for (int i=c-1; i<n; i+=w) {
                cons += s[i];
            }
            if (cons == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;


    return 0;
}

