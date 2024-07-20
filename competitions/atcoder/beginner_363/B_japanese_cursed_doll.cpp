#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    for (int i=0; i<n; i++) {
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    int counter = 0;

    while (l[n-p]<t) {
        l[n-p] += 1;
        counter += 1;
    }

    cout << counter << endl;

    




    return 0;
    
}

