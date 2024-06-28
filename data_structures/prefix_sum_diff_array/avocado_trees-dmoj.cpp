#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q, h;
    cin >> n >> q >> h;
    vector<pair<int, int>> trees(n);
    for (int i=0; i<n; i++) {
        cin >> trees[i].first >> trees[i].second;
    }
    vector<ll> pre(n);
    if (trees[0].first<=h) {
        pre[0] = trees[0].second;
    } else {
        pre[0] = 0;
    }

    for (int i=1; i<n; i++) {
        if (trees[i].first<=h) {
            pre[i] = pre[i-1] + trees[i].second;
        } else {
            pre[i] = pre[i-1];
        }
    }

    ll max_av = 0;
    int a, b;

    for (int i=0; i<q; i++) {
        cin >> a >> b;
        if (a==1) {
            max_av = max(pre[b-1], max_av);
        } else {
            max_av = max(pre[b-1]-pre[a-2], max_av);
        }
    }
    cout << max_av << endl;

    return 0;
}

