#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//dp
    //unbounded knapsack (can repeat items) / coin change problem

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int dist, n;
    cin >> dist;
    cin >> n;
    vector<int> clubs(n);
    for (int i=0; i<n; i++) {
        cin >> clubs[i];
    }
    
    //dp state based on distance values (num of strokes to reach each distance value)
    vector<ll> dp(dist+1, LLONG_MAX);
    dp[0] = 0;

    for (int i=1; i<=dist; i++) {
        for (int j=0; j<n; j++) {
            if (i>=clubs[j] and dp[i-clubs[j]]!=LLONG_MAX) 
                //adding on the amount of strokes before distance of jth club
                dp[i] = min(dp[i], dp[i-clubs[j]]+1);
        }
    }

    if (dp[dist]==LLONG_MAX) {
        cout << "Roberta acknowledges defeat." << endl;
    } else {
        cout << "Roberta wins in " << dp[dist] << " strokes." << endl; 
    }


    return 0;
}

