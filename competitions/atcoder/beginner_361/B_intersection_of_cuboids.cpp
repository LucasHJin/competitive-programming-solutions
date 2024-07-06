#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;
    //check overlapping ranges (AD, GJ) (BE, HK), (CF, IL)
    bool x = (a < j and g < d);
    bool y = (b < k and h < e);
    bool z = (c < l and i < f);

    if (x and y and z) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    
    return 0;
}

