#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;


int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if ((y>=z and x<=z) or (x>=z and y<=z)) {
        cout << "Yes" << endl;
    } else {
        cout <<"No" << endl;
    }

    return 0;
}