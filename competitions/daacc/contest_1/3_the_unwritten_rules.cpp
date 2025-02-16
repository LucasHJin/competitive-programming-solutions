#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool good = true;
    queue<pair<vector<int>, vector<int>>> bus; //each row of bus is queue represented by left and right deques
    int start = 1;

    //fill up the deques
    for (int i=0; i<n; i++) {
        vector<int> l, r;
        for (int j=0; j<m; j++) {
            l.push_back(start+j);
        }
        for (int j=m-1; j>=0; j--) {
            r.push_back(start+m+j);
        }
        bus.push({l, r});
        start += 2*m;
    }

    for (int i=0; i<2*n*m; i++) {
        int stud;
        cin >> stud;

        auto &l = bus.front().first;
        auto &r = bus.front().second;

        if (!l.empty() and stud==l.back()) { // if next to be removed from left
            l.pop_back();
        } else if (!r.empty() and stud==r.back()) { // if next to be removed from right
            r.pop_back();
        } else {
            good = false;
            break;
        }

        if (l.empty() and r.empty()) { // row emptied out
            bus.front().first.clear(); // clear out rows to avoid mle
            bus.front().second.clear();
            bus.pop();
        }
    }

    if (good) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}