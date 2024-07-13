#include <bits/stdc++.h>
#include <iostream>

 
typedef long long ll;
 
using namespace std;




int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int r, g, b;
    string c;
    cin >> r >> g >> b;
    cin >> c;
    if (c=="Blue") {
        cout << min(r, g) << endl;
    } else if (c=="Green") {
        cout << min(r, b) << endl;
    } else {
        cout << min(g, b) << endl;
    }

    return 0;
}

