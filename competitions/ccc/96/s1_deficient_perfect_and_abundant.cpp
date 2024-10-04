#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int x=0; x<n; x++) {
        int z;
        cin >> z;
        int sum = 0;
        for (int i=1; i<=z/2; i++) {
            if (z%i==0) {
                sum += i;
            }
        }
        if (sum>z) {
            cout << z << " is an abundant number." << endl;
        } else if (sum==z) {
            cout << z << " is a perfect number." << endl;
        } else {
            cout << z << " is a deficient number." << endl;
        }
    }


    return 0;
}

