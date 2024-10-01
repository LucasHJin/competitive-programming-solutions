#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> k;
    vector<int> ans;
    for (int i=0; i<k; i++) {
        int n;
        cin >> n;
        if (n!=0) {
            ans.push_back(n);
        } else {
            ans.pop_back();
        }
    }
    if (ans.size()!=0) {
        int a=0;
        for (auto it: ans) {
            a += it;
        } 
        cout << a << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

