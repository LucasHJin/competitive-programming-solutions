#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //boundaries
    ll c, r;
    cin >> c >> r;
    ll x, y;
    x=0;
    y=0;
    while (true) {
        ll a, b;
        cin >> a >> b;
        if (a==0 && b==0) {
            break;
        }
        if (x+a>c) {
            x = c;
        } else if (x+a<0) {
            x = 0;
        } else {
            x += a;
        }
        if (y+b>r) {
            y = r;
        } else if (y+b<0) {
            y = 0;
        } else {
            y += b;
        }
        cout << x << " " << y << endl;
    }


    return 0;
}
