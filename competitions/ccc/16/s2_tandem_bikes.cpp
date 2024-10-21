#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    int n;
    cin >> n;
    vector<int> d(n);
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    sort(d.begin(), d.end());
    int ans = 0;
    if (q==1) {
        for (int i=0; i<n; i++) {
            ans += max(p[i], d[i]);
        }
    } else {
        reverse(d.begin(), d.end());
        for (int i=0; i<n; i++) {
            ans += max(p[i], d[i]);
        }
    }
    cout << ans << endl;


    return 0;
}
