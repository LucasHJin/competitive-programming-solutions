#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;

bool fir(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0]; //if a<b -> true -> a is first, opposite if b<a
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> giants(n, vector<int>(3));

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int diff = b-a;
        giants[i][0] = diff;
        giants[i][1] = a;
        giants[i][2] = b;
    }

    sort(giants.begin(), giants.end(), fir);

    ll height = 0;

    for (auto it: giants) {
        height += it[1];
    }
    height -= giants[n-1][1];
    height += giants[n-1][2];

    cout << height << endl;

    return 0;
}