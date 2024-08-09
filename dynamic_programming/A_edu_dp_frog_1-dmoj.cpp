#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n+1);
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n+1, INT_MAX);
    dp[1] = 0;

    for (int i=1; i<=n; i++) {
        if (i+1<=n) {
            dp[i+1] = min(dp[i+1], dp[i]+abs(h[i]-h[i+1]));
        }
        if (i+2<=n) {
            dp[i+2] = min(dp[i+2], dp[i]+abs(h[i]-h[i+2]));
        }
    }

    cout << dp[n] << endl;

    return 0;
}

