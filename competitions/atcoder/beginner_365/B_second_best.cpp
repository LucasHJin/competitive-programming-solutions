#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.rbegin(), a.rend());
    /*
    for (int i=0; i<n; i++) {
        cout << a[i].first << " " << a[i].second <<endl;
    }
    */

    cout << a[1].second << endl;


    return 0;
}