#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//hasmap approach -> check and update

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    unordered_map<int, int> last_seen;
    vector<int> b;

    for (int i=0; i<n; i++) {
        if (last_seen.find(a[i]) != last_seen.end()) {
            b.push_back(last_seen[a[i]]+1);
        } else {
            b.push_back(-1);
        }
        last_seen[a[i]] = i;
    }

    for (auto it: b) {
        cout << it << " ";
    }
    
    return 0;
}
