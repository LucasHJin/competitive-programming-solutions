#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n==m or n==m-1) {
        cout << "stressed" << endl;
    } else if (n<m-1) {
        cout << "okay" << endl;
    } else {
        cout << "relaxed" << endl;
    }


    return 0;
}
