#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, c;
    cin >> n >> c;
    int ans = 0;
    int last = -10000;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        if (t-last>=c) {
            ans++;
            last=t;
        }
    }
    cout << ans << endl;

    return 0;
}
