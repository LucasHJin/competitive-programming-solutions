#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

struct points {
    int a;
    int b;
    int c;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<points> happy(n+1);
    for (int i=1; i<=n; i++) {
        cin >> happy[i].a >> happy[i].b >> happy[i].c;
    }
    
    vector<vector<int>> dp(n+1, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i=1; i<=n; i++) {
        //add up previous max + current
        dp[i][0] = max(dp[i-1][1], dp[i-1][2])+happy[i].a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2])+happy[i].b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1])+happy[i].c;
    }

    int ans = max(dp[n][0], dp[n][1]);
    ans = max(ans, dp[n][2]);
    cout << ans << endl;


    return 0;
}

