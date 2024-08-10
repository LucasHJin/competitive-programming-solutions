#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> h(n+1);
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n+1, INT_MAX);

    dp[1] = 0;

    //O(n*k)
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=i+k; j++) {
            //cout << i << " " << j << endl;
            if (j<=n)
                dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]));
        }
    }

    cout << dp[n] << endl;


    return 0;
}

