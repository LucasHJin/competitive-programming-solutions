#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    int c=0;
    for (int i=0; i<n/2; i++) {
        if (h[i]==h[n/2+i]) {
            c+=2;
        }
    }
    cout << c << endl;

    return 0;
}

