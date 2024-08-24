#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int d;
    string x;
    cin >> d >> x;

    for (int i=0; i<d-1; i++) {
        if (x[i] < x[i + 1]) {
            swap(x[i], x[i+1]);
            break; 
        }
    }

    cout << x << endl;

    return 0;
}

