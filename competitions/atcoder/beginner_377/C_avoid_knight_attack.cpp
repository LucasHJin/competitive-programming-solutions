#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m; //size n by n
    set<pair<ll, ll>> bad; //set supports pair, unordered doesn't
    vector<int> v = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> h = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b; // (b, a)
        bad.insert({a, b});
        for (int j=0; j<8; j++) {
            if (a+v[j]>0 and a+v[j]<=n and b+h[j]>0 and b+h[j]<=n) {
                bad.insert({a+v[j], b+h[j]});
            }
        }
    }
    ll ans = n*n;
    ans -= bad.size();
    cout << ans << endl;

    return 0;
}
