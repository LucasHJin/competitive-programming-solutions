#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    for (ll x=0; x<t; x++) {
        int n, m, k; //k is subsquare side length
        cin >> n >> m >> k;
        int w;
        cin >> w;
        vector<ll> heights(w);
        for (int i=0; i<w; i++) {
            cin >> heights[i];
        }

        sort(heights.begin(), heights.end());
        reverse(heights.begin(), heights.end());

        //+1 for easy boundary handling
        vector<vector<ll>> preSum(n+1, vector<ll>(m+1, 0));
    
        //difference array (but using prefix for space efficiency)
        for (int i=0; i<=n-k; i++) {
            for (int j=0; j<=m-k; j++) {
                //marking start of subsquare (so that you can psa later on)
                preSum[i+1][j+1]++;
                //end of subsquare vertically
                if (i+k<n) 
                    preSum[i+k+1][j+1]--;
                //end of subsquare horizontally
                if (j+k<m) 
                    preSum[i+1][j+k+1]--;
                //adding back twice subtracted area
                if (i+k<n&&j+k<m) 
                    preSum[i+k+1][j+k+1]++;
            }
        }
        
        //creating prefix sum
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                preSum[i][j] += preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
            }
        }

        unordered_map<ll, ll> counts;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (counts.find(preSum[i][j]) == counts.end()) {
                    counts[preSum[i][j]] = 1;
                } else {
                    counts[preSum[i][j]] += 1;
                }
            } 
        }

        vector<pair<ll, ll>> sortedCounts(counts.begin(), counts.end());

        sort(sortedCounts.begin(), sortedCounts.end());
        reverse(sortedCounts.begin(), sortedCounts.end());

        ll total = 0;
        ll count = 0;

        for (int i=0; i<w; i++) {
            if (sortedCounts[count].second != 0) {
                total += heights[i] * sortedCounts[count].first;
                ll temp = sortedCounts[count].second;
                sortedCounts[count].second = temp-1;
            } else {
                count += 1;
                total += heights[i] * sortedCounts[count].first;
                ll temp = sortedCounts[count].second;
                sortedCounts[count].second = temp-1;
            }
        }

        cout << total << endl;
        

    }
}

