#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k, j;
    cin >> n >> k >> j;
    vector<vector<ll>> x(3, vector<ll>(n));
    vector<vector<ll>> diff(3, vector<ll>(n));

    //mark down diff array increments + decrements
    for (int a=0; a<j; a++) {
        int l, r, i, t;
        cin >> l >> r >> i >> t;
        if (r==n) {
            diff[t-1][l-1] += i;
        } else {
            diff[t-1][l-1] += i;
            diff[t-1][r] -= i;
        }
    }

    x[0][0] = diff[0][0];
    x[1][0] = diff[1][0];
    x[2][0] = diff[2][0];

    //prefix sum to get back changes in normal array
    //this works because within the diff:
        //by making the left increment by the value, the prefix sum adds this value to all future values
        //so when it reaches the right index and sees the -value, it stops adding that value
    for (int i=0; i<3; i++) {
        for (int a=1; a<n; a++) {
            x[i][a]=diff[i][a]+x[i][a-1];
        }
    }

    //checking how many spells can still be cast
    for (int i=0; i<3; i++) {
        int counter = 0;
        for (int a=0; a<n; a++) {
            if (x[i][a]<k) {
                counter += 1;
            }
        }
        cout << counter << endl;
    }

    return 0;
}

