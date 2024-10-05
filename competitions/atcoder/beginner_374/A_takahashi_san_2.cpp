#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    if (s.size() >= 3 && s.substr(s.size()-3) == "san") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
