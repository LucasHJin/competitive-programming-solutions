#include <bits/stdc++.h>
#include <iostream>

 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    ll l_bound = 0;
    ll r_bound = 0;
    for (int i=0; i<n; i++) {
        cin >> lr[i].first >> lr[i].second;
        l_bound += lr[i].first;
        r_bound += lr[i].second;
    }

    if (l_bound<=0 and r_bound>=0) {
        cout << "Yes" << endl;
        vector<int> good;
        for (int i=0; i<n; i++) {
            good.push_back(lr[i].first);
        }
        ll curr_sum = l_bound;
        ll need = 0-curr_sum;

        for (int i=0; i<n; i++) {
            ll incr = min(need, (ll)lr[i].second-lr[i].first);
            good[i] += incr;
            need -= incr;
            if (need == 0) {
                break;
            }
        }

        if (need == 0) {
            for (int i=0; i<n; i++) {
                cout << good[i] << " ";
            }
            cout << endl;
        } else {
            //redundant but just in case
            cout << "No" << endl;
        }
        
    } else {
        cout << "No" << endl;
    }


    return 0;
}

