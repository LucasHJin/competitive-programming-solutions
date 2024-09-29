#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

bool comp_val(pair<ll, string> a, pair<ll, string> b) {
    if (a.first!=b.first) {
        return a.first>b.first;
    } else {
        return a.second<b.second;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n>=2) {
        vector<pair<ll, string>> ranks(n);
        for (int i=0; i<n; i++) {
            string comp;
            int r, s, d;
            cin >> comp >> r >> s >> d;
            ranks[i] = {2*r+3*s+d, comp};
        }
        sort(ranks.begin(), ranks.end(), comp_val);

        cout << ranks[0].second << endl;
        cout << ranks[1].second << endl;
    } else if (n==1) {
        string comp;
        int r, s, d;
        cin >> comp >> r >> s >> d;
        cout << comp << endl;
    }


    return 0;
}

