#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    int temp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin >> temp;
            triangle[i].push_back(temp);
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = triangle[0][0];

    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (j-1>=0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+triangle[i][j]);
            }
            if (j<i) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+triangle[i][j]);
            }
        }
    }

    ll ans = 0;

    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
 

}

