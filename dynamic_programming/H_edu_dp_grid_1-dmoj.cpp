#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> graph(h, vector<char>(w, '.'));
    for (int i=0; i<h; i++) {
        string row;
        cin >> row;
        for (int j=0; j<w; j++) {
            char cell;
            cell = row[j];
            if (cell=='#') {
                graph[i][j] = '#';
            }
        }
    }

    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (graph[i][j] == '.') {
                if (i>0) {
                    //don't need to check if graph is # because then it's 0
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] = dp[i][j]%1000000007;
                }
                if (j>0) {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] = dp[i][j]%1000000007;
                }
            }
        }
    }

    cout << dp[h-1][w-1] << endl;


}

