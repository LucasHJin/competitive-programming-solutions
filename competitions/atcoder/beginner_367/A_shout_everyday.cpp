#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    
    if (b < c) {
        if (a >= b and a < c) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        if (a >= b or a < c) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;

    
}

