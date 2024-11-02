#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    vector<int> a(4);
    for (int i=0; i<4; i++) {
        int test;
        cin >> test;
        a[test-1]++;
    }

    int pairs = 0;
    for (int i=0; i<4; i++) {
        pairs += a[i]/2;  
    }

    cout << pairs << endl;

    return 0;
}
