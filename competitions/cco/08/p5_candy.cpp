#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//partial solution (tles on larger cases)
    //boolean knapsack

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> cals;

    int tt_cal = 0;

    for (int i=0; i<n; i++) {
        int k, c;
        cin >> k >> c;
        tt_cal += k*c;
        for (int j=0; j<k; j++) {
            cals.push_back(c);
        }
    }

    int half_cal = tt_cal/2;

    //is it achievable to have a sum of i calories
    vector<bool> dp(half_cal+1, false);
    dp[0] = true;

    //go through the calories up to the value of each candy (subtracting)
    for (int cal: cals) {
        for (int j=half_cal; j>=cal; j--) {
            //dp[j] is true if currently achievable or achievable with previous state
            dp[j] = dp[j] || dp[j - cal];
        }
    }

    //go from middle down until find one that is reachable
    int best = 0;
    for (int i=half_cal; i>=0; i--) {
        if (dp[i]) {
            best = i;
            break;
        }
    }

    int ans = tt_cal - 2*best;
    cout << ans << endl;
    

    return 0;
}

