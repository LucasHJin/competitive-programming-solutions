#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string c="";
    int t=0;
    int min_temp = 201;
    string min_city = "";
    while (c != "Waterloo") {
        cin >> c >> t;
        if (t<min_temp) {
            min_city = c;
            min_temp = t;
        }
    }
    cout << min_city << endl;

    return 0;
}

