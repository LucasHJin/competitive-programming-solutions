#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int k, m;
    cin >> k;
    cin >> m;
    vector<int> friends(k);
    for (int i=0; i<k; i++) {
        friends[i] = i+1;
    }
    for (int x=0; x<m; x++) {
        int r;
        cin >> r;
        for (int i=r-1; i<friends.size(); i+=r) {
            friends.erase(friends.begin()+i);
            i--; //after removing an element, all elements shift to the left by 1
        }
    }
    for (auto it: friends) {
        cout << it << endl;
    }

    return 0;
}

