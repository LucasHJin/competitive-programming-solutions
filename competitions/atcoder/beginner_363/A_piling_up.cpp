#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int r;
    cin >> r;
    if (r<100) {
        cout << 100-r << endl;
    } else if (r<200) {
        cout << 200-r << endl;
    } else if (r<300) {
        cout << 300-r << endl;
    }

    return 0;
    
}

