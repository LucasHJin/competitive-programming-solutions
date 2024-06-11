#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        a[i] = i+1;
    }

    reverse(a.begin()+l-1, a.begin()+r);

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
