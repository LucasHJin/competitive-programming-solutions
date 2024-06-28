#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    vector<ll> pre(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }

    pre[0] = x[0];
    for (int i=1; i<n; i++) {
        pre[i] = pre[i-1] + x[i];
    }
    /*
    for (auto it: pre) {
        cout << it << " ";
    }
    */

   int a, b;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        if (a==1) {
            cout << pre[b-1] << endl;
        } else {
            cout << pre[b-1]-pre[a-2] << endl;
        }
    }

    return 0;
}

