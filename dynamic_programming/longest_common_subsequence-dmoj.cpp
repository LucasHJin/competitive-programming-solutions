#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> fir(n);
    vector<int> sec(m);
    for (int i=0; i<n; i++) {
        cin >> fir[i];
    }
    for (int j=0; j<m; j++) {
        cin >> sec[j];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (fir[i-1]==sec[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;

    
}

