#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    //binary search
    ll check = 0;
    for (int i=0; i<n; i++) {
        check += a[i];
    }
    if (check<=m) {
        cout << "infinite" << endl;
    } else {
        ll l=0;
        ll r=a[n-1];
        ll mid = 0;
        ll sum;
        ll answer = 0;
        while (l<=r) {
            sum = 0;
            mid = (l+r)/2;
            for (int i=0; i<n; i++) {
                sum += min((ll)a[i], mid);
            }

            if (sum<=m) {
                answer = mid;
                l = mid+1;
            } else if (sum>m) {
                r = mid-1;
            }
        }
        cout << answer << endl;
    }


    return 0;
}