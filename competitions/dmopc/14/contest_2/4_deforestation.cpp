#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> m(n);
    for (int i=0; i<n; i++) {
        cin >> m[i];
    }
    vector<ll> pre(n);
    pre[0] = m[0];
    for (int i=1; i<n; i++) {
        pre[i] = pre[i-1] + m[i];
    }

    cin >> q;
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        if (a==0) {
            cout << pre[b] << endl;
        } else {
            cout << pre[b] - pre[a-1] << endl;
        }

    }


    return 0;
}

