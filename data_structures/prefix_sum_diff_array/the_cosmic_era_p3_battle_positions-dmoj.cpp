#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int i, n, j;
    cin >> i >> n >> j;
    vector<ll> diff(i);
    int l, r, k;
    //diff array
    for (int a=0; a<j; a++) {
        cin >> l >> r >> k;
        if (r==i) {
            diff[l-1] += k;
        } else {
            diff[l-1] += k;
            diff[r] -= k;
        }
    }
    vector<ll> stations(i);
    stations[0] = diff[0];

    //sum array
    for (int a=1; a<i; a++) {
        stations[a] = diff[a] + stations[a-1];
    }

    //checking valid
    int counter = 0;
    for (int a=0; a<i; a++) {
        if (stations[a]<n) {
            counter += 1;
        }
    }

    cout << counter << endl;


    return 0;
}

