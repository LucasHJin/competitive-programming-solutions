#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//knapsack problem

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int c, m;
    cin >> c >> m;

    vector<pair<int, int>> prcs(c);
    for (int i=0; i<c; i++) {
        int n, k;
        cin >> n >> k;
        prcs[i] = {n, k};
    }

    //array based on max attainable value per every cost (based on cost)
    vector<int> dp(m+1, 0);

    for (int i=0; i<c; i++) {
        for (int j=m; j>=prcs[i].second; j--) {
            dp[j] = max(dp[j], dp[j - prcs[i].second] + prcs[i].first);
        }
    }

    int ans = *max_element(dp.begin(), dp.end());

    cout << ans << endl;

    return 0;
}

