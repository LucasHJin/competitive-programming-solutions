#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> values(n);
    vector<int> weights(n);
    int total_value = 0;
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
        total_value += values[i];
    }

    //switch it so the dp is based on value instead of weight (weight is larger size)
    vector<ll> dp(total_value + 1, 1e12 + 10);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        //go through all items such that (adding up < total value)
        for (int j=total_value; j>=values[i]; j--) {
            //if new lowest weight after adding new item
            dp[j] = min(dp[j], dp[j - values[i]] + weights[i]);
        }
    }

    ll answer = 0;
    //go through answers to find values that are smaller than max weight
    for (ll i=0; i<=total_value; i++) {
        if (dp[i] <= w) {
            //don't need to check if new max because it is ordered smallest to greatest because of dp
            answer = i;
        }
    }
    cout << answer << endl;
}

