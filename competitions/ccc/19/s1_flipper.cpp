#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string ops;
    cin >> ops;
    vector<vector<int>> a(2, vector<int>(2));
    a[0][0]=1;
    a[0][1]=2;
    a[1][0]=3;
    a[1][1]=4;
    for (auto it: ops) {
        if (it=='H') {
            swap(a[0][0], a[1][0]);
            swap(a[0][1], a[1][1]);
        } else {
            swap(a[0][0], a[0][1]);
            swap(a[1][0], a[1][1]);
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout << a[i][j] << " ";
        } cout << endl;
    }

    return 0;
}

