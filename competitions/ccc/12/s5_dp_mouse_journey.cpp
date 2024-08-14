#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int r, c;
    cin >> r >> c;
    int k;
    cin >> k;
    //cat = 1, no cat = 0
    vector<vector<int>> graph(r, vector<int>(c, 0));
    int ty, tx;
    for (int i=0; i<k; i++) {
        cin >> ty >> tx;
        ty--;
        tx--;
        graph[ty][tx] = 1;
    }

    vector<vector<ll>> dp(r, vector<ll>(c, 0));
    dp[0][0] = 1;

    //just add from top and left if possible
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (graph[i][j] == 0) {
                if (i>0)
                    dp[i][j] += dp[i-1][j]; //don't need to check for cat because graph[cat] = 0 so you would add 0
                if (j>0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }

    cout << dp[r-1][c-1] << endl;


 

}

