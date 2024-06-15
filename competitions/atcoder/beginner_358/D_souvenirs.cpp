#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(m);

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll min_sum = 0;
    for (int i=0; i<m; i++) {
        min_sum += b[i];
    }

    ll i = 0;
    ll j = 0;
    ll price = 0;

    while (i<n) {
        //cout << a[i] << " " << b[j] << " " << i << " " << j << " " << price << endl;
        if (j>=m) {
            //price = -1;
            break;
        } else {
            if (a[i]>=b[j]) {
                price += a[i];
                i+=1;
                j+=1;
            } else {
                i+=1;
            }
        }
    }

    if (price<min_sum) {
        cout << -1 << endl;
    } else {
        cout << price << endl;
    }

    return 0;
}

