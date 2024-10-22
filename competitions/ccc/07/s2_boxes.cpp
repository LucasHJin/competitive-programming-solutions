#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> boxes(n);
    for (int i=0; i<n; i++) {
        int l, w, h;
        cin >> l >> w >> h;
        boxes[i].push_back(l);
        boxes[i].push_back(w);
        boxes[i].push_back(h);
        boxes[i].push_back(static_cast<ll>(l)*w*h);
    }
    sort(boxes.begin(), boxes.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[3] < b[3]; 
    });

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int l, w, h;
        cin >> l >> w >> h;
        int good = 0;
        for (auto it: boxes) {
            if ((it[0] >= l && it[1] >= w && it[2] >= h) ||
                (it[0] >= l && it[1] >= h && it[2] >= w) ||
                (it[0] >= w && it[1] >= l && it[2] >= h) ||
                (it[0] >= w && it[1] >= h && it[2] >= l) ||
                (it[0] >= h && it[1] >= l && it[2] >= w) ||
                (it[0] >= h && it[1] >= w && it[2] >= l)) {
                good = it[3];
                break;
            }
        }
        if (good==0) {
            cout << "Item does not fit." << endl;
        } else {
            cout << good << endl;
        }
    }


    return 0;
}
