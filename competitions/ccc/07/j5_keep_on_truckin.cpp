#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    ll a, b, n;
    cin >> a;
    cin >> b;
    cin >> n;
    vector<ll> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for (ll i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        motels.push_back(temp);
    }

    sort(motels.begin(), motels.end());

    ll m = motels.size();
    vector<ll> dp(m, 0);
    dp[0] = 1;
    for (ll i=1; i<m; i++) {
        bool back = true;
        int j = i;
        while (back) {
            j -= 1;
            if (j>=0) {
                if ((motels[i]-a>=motels[j]) and (motels[i]-b<=motels[j])) {
                    dp[i] += dp[j];
                }
            } else {
                back = false;
            }
        }
    }

    cout << dp[m-1] << endl;



    


    return 0;

    
}

