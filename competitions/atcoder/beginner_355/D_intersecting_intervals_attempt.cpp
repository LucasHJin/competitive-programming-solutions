#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Pos {
    int pos;
    bool lef;
};

bool compareEvents(const Pos &a, const Pos &b) {
    if (a.pos != b.pos)
        return a.pos < b.pos; //sort by position
    else
        return a.lef; //repeated (equal ranges) L==R
}

int main() {
    int n;
    cin >> n;

    vector<Pos> endpoints(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> endpoints[2 * i].pos >> endpoints[2 * i + 1].pos;
        endpoints[2 * i].lef = true;
        endpoints[2 * i + 1].lef = false;
    }

    //sort interval endpoints
    sort(endpoints.begin(), endpoints.end(), compareEvents);

    for (auto it: endpoints) {
        cout << it.pos << it.lef << endl;
    }
    int good = 0;
    //num of intersecting range at any time
    int actR = 0;

    for (int i = 0; i < 2 * n; i++) {
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