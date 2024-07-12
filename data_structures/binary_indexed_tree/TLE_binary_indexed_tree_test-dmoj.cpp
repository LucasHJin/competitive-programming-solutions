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

auto countLE(int val, int n, vector<ll> x) {
    sort(x.begin(), x.end());
    int left = 0, right = x.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x[mid] <= val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left-1;
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

    char a;
    int b, c;
    for (int i=0; i<q; i++) {
        cin >> a;
        if (a=='C') {
            cin >> b >> c;
            update(b, n, bit, c, x);
            /*
            cout << "A ";
            for (auto it: x) {
                cout << it << " ";
            }
            cout << endl;
            cout << "B ";
            for (auto it: bit) {
                cout << it << " ";
            }
            cout << endl;
            */
        } else if (a=='S') {
            cin >> b >> c;
            if (b==1) {
                cout << pre_sum(c, bit) << endl;
            } else {
                cout << pre_sum(c, bit) - pre_sum(b-1, bit) << endl;
            }
        } else {
            cin >> b;
            cout << countLE(b, n, x) << endl;
        }
    }
    
    return 0;
}

