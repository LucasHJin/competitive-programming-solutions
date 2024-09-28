#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int counter = 0;
    int prev = 0;
    int curr = 0;
    int total = 0;
    for (char c='A'; c<='Z'; c++) {
        if (counter==0) {
            prev = s.find(c);
        } else {
            curr = s.find(c);
            total += abs(curr-prev);
            prev = curr;
        }

        counter++;
    }
    cout << total << endl;

    return 0;
}

