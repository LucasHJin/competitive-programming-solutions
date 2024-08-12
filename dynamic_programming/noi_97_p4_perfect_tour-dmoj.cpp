#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n-1));
    for (int i=0; i<m; i++) {
        int temp;
        for (int j=0; j<n-1; j++) {
            cin >> temp;
            graph[i][j] = temp;
        }
    }

    vector<vector<int>> dp(m, vector<int>(n-1));

    for (int i=0; i<m; i++) {
        dp[i][0] = graph[i][0];
    }

    for (int i=1; i<n-1; i++) {
        int ma = 0;
        for (int j=0; j<m; j++) {
            ma = max(ma, dp[j][i-1]);
        }
        for (int j=0; j<m; j++) {
            dp[j][i] = max(graph[j][i], graph[j][i]+ma);
        }
    }
    /*
    for (int i=0; i<m; i++) {
        for (int j=0; j<n-1; j++) {
            cout << dp[i][j] << " ";
        } 
        cout << endl;
    }
    */
    
    int ans;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n-1; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    


}

