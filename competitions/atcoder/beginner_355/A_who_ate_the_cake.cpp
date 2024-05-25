#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    
    if (a==b) {
        cout << -1 << endl;
    } else if (a==1 and b==3) {
        cout << 2 << endl;
    } else if (a==1 and b==2) {
        cout << 3 << endl;
    } else if (a==2 and b==1) {
        cout << 3 << endl;
    } else if (a==2 and b==3) {
        cout << 1 << endl;
    } else if (a==3 and b==1) {
        cout << 2 << endl;
    } else if (a==3 and b==2) {
        cout << 1 << endl;
    }
    
    return 0;
    
} 