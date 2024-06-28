#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int f, r;
    cin >> f >> r;
    vector<vector<int>> c(f, vector<int>(r));

    for (int i=0; i<f; i++) {
        for (int j=0; j<r; j++) {
            cin >> c[i][j];
        }
    }

    vector<vector<ll>> pre(f, vector<ll>(r));

    for (int i=0; i<f; i++) {
        pre[i][0] = c[i][0];
    }

    for (int i=0; i<f; i++) {
        for (int j=1; j<r; j++) {
            pre[i][j] = pre[i][j-1]+c[i][j];
        }
    }

    int q;
    cin >> q;
    int a, b, h;
    for (int i=0; i<q; i++) {
        cin >> a >> b >> h;
        if (a==1) {
            cout << pre[h-1][b-1] << endl;
        } else {
            cout << pre[h-1][b-1] - pre[h-1][a-2] << endl;
        }
    }



    return 0;
}

