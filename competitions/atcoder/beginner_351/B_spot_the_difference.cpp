#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> A(n, vector<char>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    int b = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char temp;
            cin >> temp;
            if (temp!=A[i][j]) {
                cout << i+1 << " " << j+1 << endl;
                b = 1;
                break;
            }
        }
        if (b==1) {
            break;
        }
    }
    
    return 0;
}