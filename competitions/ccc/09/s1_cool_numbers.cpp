#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    int counter = 0;
    int ca = round(cbrt(a)); 
    int cb = round(cbrt(b)); 
    int sa = round(sqrt(a)); 
    int sb = round(sqrt(b)); 

    for (int i=ca; i<=cb; i++) {
        for (int j=sa; j<=sb; j++) {
            if (i*i*i==j*j) {
                counter++;
            }
        }
    }

    cout << counter << endl;


    return 0;
}

