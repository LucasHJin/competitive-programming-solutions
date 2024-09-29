#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int num;
    cin >> num;
    if (num<3) {
        cout << 0 << endl;
    } else {
        unsigned long long result = 1;
        for (int i=0; i<3; i++) {
            result = result*((num-1)-i)/(i+1);
        }
        cout << result << endl;
    }

    return 0;
}

