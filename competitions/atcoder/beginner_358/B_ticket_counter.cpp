#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }

    cout << t[0]+a << endl;
    ll count = t[0]+a;

    for (int i=1; i<n; i++) { 
        if (t[i]-t[i-1]>=a and t[i]>=count) {
            cout << t[i]+a << endl;
            count = t[i]+a;
        } else {
            count += a;
            cout << count << endl;
        }
    }
    
    return 0;
}
