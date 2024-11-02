#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> collect;

    for (int i=0; i<n; i++) {
        int q, r;
        cin >> q >> r;
        collect.push_back({q, r});
    }

    int Q;
    cin >> Q;
    for (int i=0; i<Q; i++) {
        int t, d;
        cin >> t >> d;
        t--;
        
        int q = collect[t].first;
        int r = collect[t].second;

        int current = d % q;

        if (current == r) {
            cout << d << endl;
        } else if (current < r) {
            int left = r - current;
            cout << d + left << endl;
        } else {
            int left = q - (current - r);
            cout << d + left << endl;
        }
    }

    return 0;
}
