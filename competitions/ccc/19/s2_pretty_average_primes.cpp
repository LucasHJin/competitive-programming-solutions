#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

bool is_prime(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x%i==0) 
            return false;
    }
    return true;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        for (int k=2; k<n; k++) {
            int a = k;
            int b = 2*n-k;
            if (is_prime(a) and is_prime(b)) {
                cout << a << " " << b << endl;
                break;
            }
        }

    }

    return 0;
}
