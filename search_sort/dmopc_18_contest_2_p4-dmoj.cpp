#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;


int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }

    ll min_l = 9223372036854775807;
    ll sum = 0;
    int i = 0;
    int j = 0;

    while (j < n) {
        sum += d[j];
        while (sum >= m) {
            min_l = min(min_l, ll(j-i+1)); //typecasting
            sum -= d[i];
            i++;
        }
        j++;
    }
    
    if (min_l != 9223372036854775807) {
        cout << min_l << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
