#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int count=0;
    for (int i=0; i<12; i++) {
        string s;
        cin >> s;
        if (s.length()==i+1) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}

