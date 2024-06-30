#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <unordered_map>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> w(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }

    ll total = 0;
    unordered_map<int, int> aw;
    for (int i=0; i<n; i++) {
        if (aw.find(a[i]) == aw.end()) {
            aw.insert(make_pair(a[i], w[i]));
        } else {
            int tempmax;
            int tempmin;
            tempmax = max(aw[a[i]], w[i]);
            tempmin = min(aw[a[i]], w[i]);
            total += tempmin;
            aw[a[i]] = tempmax;
        }
    }

    cout << total << endl;


    return 0;
}

