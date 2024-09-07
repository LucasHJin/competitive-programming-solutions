#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    
    int current = 0;
    for (int i=0; i<n; i++) {
        if (current>=i) {
            current = a[current][i]-1;
        } else {
            current = a[i][current]-1;
        }
    }

    cout << current+1 << endl;
    
    return 0;
}