#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef long long int ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;

    map<int, int> ac;

    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;

        //not in map yet
        if (ac.find(c) == ac.end()) {
            ac[c] = a;
        } else { 
            //min value of that color
            ac[c] = min(ac[c], a);
        }
    }
    /*
    for (auto it: ac) {
        cout << it.first << " " << it.second << endl;
    } */

    //most delicious
    int maxDel = -1;
    for (auto pair : ac) {
        maxDel = max(maxDel, pair.second);
    }

    cout << maxDel << endl;

    return 0;
}