#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    ll l = 0;
    ll r = 2000000000;
    ll guess;
    string answer;

    while (answer != "OK") {
        if (l>r) {
            break;
        }
        guess = l+(r-l)/2+1; //=(l+r)/2 but no overflow
        cout << guess << endl;

        cin >> answer;
        if (answer == "SINKS") {
            l = guess + 1; 
        } else if (answer == "FLOATS") {
            r = guess - 1; 
        }
    }

    return 0;
}