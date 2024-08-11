#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //size, max weight
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> knapsack(n);
    for (int i=0; i<n; i++) {
        cin >> knapsack[i].first >> knapsack[i].second;
    }

    vector<ll> dp(c+1, 0);

    //for each item (weight + value)
    for (int i=0; i<n; i++) {
        //iterate through the current values that are w below or lower (can't have above because then capacity is exceeded)
            //going downwards or else could you calculated value of smaller weight where item is already used
        for (int j=c; j>=knapsack[i].first; j--) {
            //compare max of not including vs including ith item
                //subtract the weight because can only go from that item and below
            dp[j] = max(dp[j], dp[j-knapsack[i].first]+knapsack[i].second);
        }
    }

    cout << dp[c] << endl;

    return 0;
}

