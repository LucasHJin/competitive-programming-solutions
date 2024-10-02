#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n+1);
    for (int i=0; i<n+1; i++) {
        cin >> h[i];
    }
    vector<int> w(n);
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }

    ll area = 0;
    for (int i=0; i<n; i++) {
        int h1 = h[i];
        int h2 = h[i+1];
        int w1 = w[i];
        area += (h1 + h2) * w1;
    }
    cout << area / 2;
    if (area % 2 == 1) {
        cout << ".5";
    }
    cout << endl;


    return 0;
}

