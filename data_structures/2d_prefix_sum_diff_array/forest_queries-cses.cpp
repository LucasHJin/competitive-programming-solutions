#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char temp;
            cin >> temp;
            if (temp=='*') {
                forest[i][j]=1;
            } else {
                forest[i][j]=0;
            }
        }
    }
    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << forest[i][j] << " ";
        }
        cout << endl;
    }
    */

    vector<vector<ll>> prefix(n, vector<ll>(n));
    prefix[0][0] = forest[0][0];
    for (int i=1; i<n; i++) {
        prefix[0][i] = prefix[0][i-1] + forest[0][i];
    }
    for (int i=1; i<n; i++) {
        prefix[i][0] = prefix[i-1][0] + forest[i][0];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + forest[i][j];
        }
    }

    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    */


    int x1, y1, x2, y2;
    for (int k=0; k<q; k++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        ll result = prefix[x2][y2];
        if (x1>0) 
            result -= prefix[x1-1][y2];
        if (y1>0) 
            result -= prefix[x2][y1-1];
        if (x1>0 and y1>0) 
            result += prefix[x1-1][y1-1];

        cout << result << endl;
    }
    

    return 0;
}

