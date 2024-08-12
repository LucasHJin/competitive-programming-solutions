#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, 0);

    dp[0] = arr[0];

    for (int i=1; i<n; i++) {
        //either use previous (adjacent so can't use current) or use current + from 2 ago
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }
    
    cout << dp[n-1] << endl;



}

