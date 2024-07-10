#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }

    //precompute log, start at 1 because log1 = 0
    ll lg[n+1];
    lg[1] = 0;
    for (int i=2; i<=n; i++) {
        lg[i] = lg[i/2] + 1;
    }

    //# of levels of st
    ll k = lg[n];

    //sparse table
    ll st[k + 1][n];

    //base case (leaf nodes)
    for (int j=0; j<n; j++) {
        st[0][j] = x[j];
    }

    //building st
    //start at i=1 because already got base
    for (int i=1; i<=k; i++) {
        for (int j=0; j + (1 << i) <= n; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i - 1))]);
        }
    }

    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        --l; --r; 

        int len = r-l+1;
        int p = lg[len]; //max power of 2 in len

        int min_val = min(st[p][l], st[p][r-(1<<p)+1]);
        cout << min_val << endl;
    }

    return 0;
}

