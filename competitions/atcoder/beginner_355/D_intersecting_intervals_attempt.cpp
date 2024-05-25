#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

struct Pos {
    int pos;
    bool lef;
};

bool comp(const Pos &a, const Pos &b) {
    if (a.pos != b.pos)
        return a.pos < b.pos; //sort by position
    else
        return a.lef; //repeated (equal ranges) L==R
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    
    int n;
    cin >> n;

    Pos endpoints[2*n];

    for (int i=0; i<n; i++) {
        int left, right;
        cin >> left >> right;
        endpoints[2 * i].pos = left;
        endpoints[2 * i].lef = true;
        endpoints[2 * i+1].pos = right;
        endpoints[2 * i+1].lef = false;
    }

    //sort interval endpoints
    //sort(endpoints.begin(), endpoints.end(), comp);
    sort(endpoints, endpoints + 2*n, comp);

    //for (auto it: endpoints) {
    //    cout << it.pos << it.lef << endl;
    //}
    ll good = 0;
    //num of intersecting range at any time
    ll actR = 0;

    for (int i=0; i<2*n; i++) {
        if (endpoints[i].lef) {
            //add intersect
            actR++;
        } else {
            //loss intersect
            actR--;
            // Add to the counter because it means that it was intersecting before and we know how many it was intersecting with
            good += actR;
        }
    }

    cout << good << endl;

    return 0;
}