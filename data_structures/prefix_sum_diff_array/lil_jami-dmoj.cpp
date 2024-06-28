#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k, q;
    cin >> n >> k;
    vector<int> stones(n);
    int temp;
    for (int i=0; i<k; i++) {
        cin >> temp;
        stones[temp]+=1;
    }
    vector<ll> pre(n);
    pre[0] = stones[0];
    for (int i=1; i<n; i++) {
        pre[i] = pre[i-1] + stones[i];
    }

    cin >> q;
    int a, b;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        if (a==0) {
            cout << pre[b] << endl;
        } else {
            cout << pre[b]-pre[a-1] << endl;
        }
    }



    return 0;
}

