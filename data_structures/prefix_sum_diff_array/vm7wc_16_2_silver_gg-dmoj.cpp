#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string gstr;
    cin >> gstr;
    int n;
    cin >> n;
    vector<ll> integrity(gstr.size());
    if (gstr[0]=='G') {
        integrity[0] = 1;
    } else {
        integrity[0] = 0;
    }
    for (int i=1; i<gstr.size(); i++) {
        if (gstr[i]=='G') {
            integrity[i] = integrity[i-1] + 1;
        } else {
            integrity[i] = integrity[i-1];
        }
    }
    int l, r;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        if (l==0) {
            cout << integrity[r] << endl;
        } else {
            cout << integrity[r] - integrity[l-1] << endl;
        }
    }


    return 0;
}

