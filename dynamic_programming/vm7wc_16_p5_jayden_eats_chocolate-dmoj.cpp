#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//reverse coin change (max instead of min)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> xyz(3);
    cin >> n;
    cin >> xyz[0] >> xyz[1] >> xyz[2];

    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<3; j++) {
            if (i-xyz[j]>=0 and dp[i-xyz[j]]!=-1) {
                dp[i] = max(dp[i], dp[i-xyz[j]]+1);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}

