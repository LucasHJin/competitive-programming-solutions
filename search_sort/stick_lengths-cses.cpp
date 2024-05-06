#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    
    ll median = p[n/2];
    ll total = 0;
    
    for (int i=0; i<n; i++) {
        if (p[i]!=median) {
            total += abs(median-p[i]);
        }
    }
    
    cout << total << endl;
 
 
    return 0;
}