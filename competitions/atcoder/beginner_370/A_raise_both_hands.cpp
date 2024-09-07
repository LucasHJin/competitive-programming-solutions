#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int l, r;
    cin >> l >> r;
    if ((l==1 and r==1) or  (l==0 and r==0)) {
        cout << "Invalid" << endl;
    } else if (l==1) { 
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}