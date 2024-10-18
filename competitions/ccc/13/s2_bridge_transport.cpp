#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int w, n;
    cin >> w;
    cin >> n;
    vector<int> cars(n);
    for (int i=0; i<n; i++) {
        cin >> cars[i];
    }

    int weight = 0;
    int ans = n;
    for (int i=0; i<n; i++) {
        weight += cars[i];
        if (i>=4) {
            weight -= cars[i-4];
        }
        if (weight>w) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
