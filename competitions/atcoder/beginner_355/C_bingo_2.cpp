#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    for (int i=0; i<t; i++) {
        cin >> a[i];
    }
    
    int x = 0;
    int good = -10;

    vector<int> rows(n);
    vector<int> cols(n);
    int diag1 = 0;
    int diag2 = 0;

    
    for (int turn = 0; turn < t; turn++) {
        int num = a[turn];
        //cout << num << endl;
        int c = (num-1) % n + 1;
        int r = (num-c)/n + 1;
        c -= 1;
        r -= 1;

        //cout << r << " " << c << endl;

        rows[r]++;
        cols[c]++;
        
        //diagonal 1
        if (r == c) {
            diag1++;
        }
        
        //diagonal 2
        if (r + c == n - 1) {
            diag2++;
        }
        
        //rows, columns
        if (rows[r] == n or cols[c] == n or diag1 == n or diag2 == n) {
            x = 1;
            good = turn;
            break;
        }
    }


    if (x==0) {
        cout << -1 << endl;
    } else {
        cout << good+1 << endl;
    }

    return 0;   
} 