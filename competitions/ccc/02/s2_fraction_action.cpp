#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, d;
    cin >> n >> d;
    int ans = n/d;
    int rem = n%d;
    int x = gcd(rem, d);
    if (ans != 0 and rem != 0) {
        cout << ans << " " << rem/x << "/" << d/x << endl;
    } else if (rem == 0) {
        cout << ans << endl;
    } else if (ans == 0) {
        cout << rem/x << "/" << d/x << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
