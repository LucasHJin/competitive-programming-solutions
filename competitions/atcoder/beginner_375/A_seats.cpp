#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c=0;
    for (int i=0; i<=n-2; i++) {
        if (s[i]=='#' and s[i+2]=='#' and s[i+1]=='.') {
            c++;
        }
    }
    cout << c << endl;

    return 0;
}
