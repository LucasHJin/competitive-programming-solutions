#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> height(n);
    for (int i=0; i<n; i++) {
        cin >> height[i];
    }

    sort(height.begin(), height.end());
    
    int l = height[0];
    int r = height[n-1];
    ll guess_val = 0;
    ll sum;
    ll ans;

    while (l <= r) {
        guess_val = l+(r-l)/2;
        
        sum = 0;
        for (int i=0; i<n; i++) {
            if (height[i]>guess_val) {
                sum += height[i]-guess_val;
            }
        }

        if (sum == m) {
            ans = guess_val;
            break;
        } else if (sum > m) {
            ans = guess_val;
            l = guess_val + 1;
        } else {
            r = guess_val - 1;
        }
        /*
        also works
        
        if (sum >= m) {
            ans = guess_val; 
            l = guess_val + 1; 
        } else {
            r = guess_val - 1; 
        }
        */
    }

    cout << ans << endl;



    return 0;
}


