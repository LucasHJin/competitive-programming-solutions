#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int x;
    cin >> x;

    int c=0;
    for (int i=0; i<x/4+1; i++) {
        int rem = x-i*4;
        if (rem%5==0) {
            c++;
        }
    }
    cout << c << endl;

    return 0;
}

