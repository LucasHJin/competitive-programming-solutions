#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int mini = 2147483647;
    int diff = 0;
    for (ll i=0; i+(n-k)-1<n; i++) {
        //cout << "A" << i+n-k-1 << i <<endl;
        diff = a[i+(n-k)-1]-a[i];
        mini = min(diff, mini);
    }

    cout << mini << endl;

    
    return 0;
}

