#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> coords(n);
    for (int i=0; i<n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }

    sort(coords.begin(), coords.end());

    double m = 0;
    for (int i=1; i<n; i++) {
        double val = (abs(coords[i].second-coords[i-1].second)/(double)(abs(coords[i].first-coords[i-1].first))); //manually set as double
        m = max(val, m);
    }

    cout << fixed << setprecision(5) << m << endl;

    return 0;
}

