#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string e;
    cin >> e;
    int n;
    cin >> n;
    vector<pair<int, string>> moves(n);
    for (int i=0; i<n; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    int dmg = 0;

    for (auto it: moves) {
        if (e=="FIRE") {
            if (it.second=="FIRE") {
                dmg = max(dmg, it.first);
            } else if (it.second=="GRASS") {
                dmg = max(dmg, int(floor(0.5*it.first)));
            } else {
                dmg = max(dmg, 2*it.first);
            }
        } else if (e=="WATER") {
            if (it.second=="FIRE") {
                dmg = max(dmg, int(floor(0.5*it.first)));
            } else if (it.second=="GRASS") {
                dmg = max(dmg, 2*it.first);
            } else {
                dmg = max(dmg, it.first);
            }
        } else {
            if (it.second=="FIRE") {
                dmg = max(dmg, 2*it.first);
            } else if (it.second=="GRASS") {
                dmg = max(dmg, it.first);
            } else {
                dmg = max(dmg, int(floor(0.5*it.first)));
            }
        }
    }

    cout << dmg << endl;

    return 0;
}
