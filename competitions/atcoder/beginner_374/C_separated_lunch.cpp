#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }
    sort(k.begin(), k.end());

    ll total = 0;
    for (int i=0; i<n; i++) {
        total += k[i];
    }

    ll ans = total;
    //goes from 0 to 2^n-1 -> 1<<n=2^n
    for (int i=0; i<(1<<n); i++) {
        ll ga = 0;
        
        for (int j=0; j<n; j++) {
            //1 << j creates a bitmask where only jth index is set, i.e. 0000...0100
            if (i&(1<<j)) { //i&(1<<j) checks if the j-th bit in i is 1
                ga += k[j]; //only does it if 1&1=1
            }
        }

        ll gb = total - ga;

        //min of max
        ll max_ppl = max(ga, gb);
        ans = min(ans, max_ppl);
    }

    cout << ans << endl;

     

    return 0;
}
