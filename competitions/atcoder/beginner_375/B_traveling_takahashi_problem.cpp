#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> points;
    for (int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    double total_cost = 0.0;
    pair<int, int> curr = {0, 0};
    for (int i=0; i<n; i++) {
        ll dx = points[i].first-curr.first;
        ll dy = points[i].second-curr.second;
        total_cost += sqrt(dx*dx + dy*dy);
        curr = points[i];
    }
    //need to static cast as ll to implicitly work
    total_cost += sqrt(static_cast<long long>(curr.first) * curr.first + static_cast<long long>(curr.second) * curr.second);
    cout << fixed << setprecision(7) << total_cost << endl;

    return 0;
}
