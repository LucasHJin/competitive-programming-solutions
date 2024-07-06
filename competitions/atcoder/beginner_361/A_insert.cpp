#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n+1; i++) {
        if (i<k) {
            cout << a[i] << " ";
        } else if (i==k) {
            cout << x << " ";
        } else {
            cout << a[i-1] << " ";
        }
    }


    return 0;
}

