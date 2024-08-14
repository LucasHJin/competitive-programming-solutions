#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> ss(n);
    for (int i=0; i<n; i++) {
        cin >> ss[i];
    }

    //needs to be 0, not 1 or else if it restarts, i.e. 4 5 1, it will need to be 1 element, not 0
    vector<int> dp(n, 1);

    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (ss[j]<ss[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
 

}

