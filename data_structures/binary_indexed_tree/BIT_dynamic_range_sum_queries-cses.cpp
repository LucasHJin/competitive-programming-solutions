#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
const int maxN = 2e5;
 
using namespace std;

//O(logn)
ll pre_sum(int idx, ll bit[]) {
    ll sum = 0;
    while (idx>0) {
        sum += bit[idx];
        //bit expression go to next good (1, 2, 4...)
        idx -= (idx & (-idx));
    }
    return sum;
}

//O(logn)
void add(int idx, int n, ll bit[], int val) {
    while (idx<=n) {
        bit[idx] += val;
        //bit expression go to next good (1, 2, 4...)
        idx += (idx & (-idx));
    }
}

//O(logn)
void update(int idx, int n, ll bit[], int val, vector<ll>& x) {
    ll temp = val - x[idx];
    int temp2 = idx;
    while (idx<=n) {
        bit[idx] += temp;
        idx += (idx & (-idx));
    }
    x[temp2] = val;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> x(n+1);
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
    ll bit[maxN+1];
    for (int i=0; i<=n; i++) {
        bit[i] = 0;
    }
    
    for (int i=1; i<=n; i++) {
        add(i, n, bit, x[i]);
    }

    int a, b, c;
    for (int i=0; i<q; i++) {
        cin >> a >> b >> c;
        if (a==1) {
            update(b, n, bit, c, x);
        } else {
            if (b==1) {
                cout << pre_sum(c, bit) << endl;
            } else {
                cout << pre_sum(c, bit) - pre_sum(b-1, bit) << endl;
            }
        }
    }
    
    return 0;
}

