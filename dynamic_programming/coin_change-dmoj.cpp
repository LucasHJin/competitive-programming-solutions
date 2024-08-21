#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//coin change problem (see how many to reach each smaller value)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int x, n;
    cin >> x;
    cin >> n;
    vector<int> coins(n);
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    
    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (i-coins[j]>=0 and dp[i-coins[j]]!=INT_MAX) {
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    
    cout << dp[x] << endl;


    return 0;
}

