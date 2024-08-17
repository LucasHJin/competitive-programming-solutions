#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string x;
    cin >> x;

    while (!x.empty() and x.back() == '0') {
        x.pop_back();
    }

    if (!x.empty() and x.back() == '.') {
        x.pop_back();
    }

    if (x.empty()) {
        x = "0";
    }

    cout << x << endl;
    return 0;


    
}

