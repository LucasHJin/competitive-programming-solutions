#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s;
    cin >> t;

    int n = s.size();
    int m = t.size();

    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //find length
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i-1]==t[j-1]) {
                //diagonal = previous best
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                //hor/vert = stays same
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    //reverse engineer answer
    string ans;
    int i = n;
    int j = m;
    while (i>0 and j>0) {
        if (s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--;
            j--;
        } else if (dp[i][j-1] >= dp[i-1][j]) {
            j--; //move back for the t string (to get bigger value)
        }
        else {
            i--; //move back for the s string
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    

    /*
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i-1] == t[j-1]) {
                //previous and back (diagonal)
                curr[j] = prev[j-1] + s[i-1];
            } else {
                //checking previous row and previous column (left and up)
                curr[j] = max(curr[j-1], prev[j]);
            }
        }
        //move current row to previous row
        for (int j=0; j<=m; j++) {
            prev[j] = curr[j];
        }
    }

    cout << prev[m] << endl;
    */

}

