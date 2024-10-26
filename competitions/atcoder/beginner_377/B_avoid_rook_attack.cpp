#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    vector<bool> row(8, true);
    vector<bool> col(8, true);
    for (int i=0; i<8; i++) {
        string line;
        cin >> line;
        for (int j=0; j<8; j++) {
            char cell = line[j];
            if (cell == '#') {
                row[i] = false;
                col[j] = false;
            }
        }
    }

    int c = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (row[i] and col[j]) {
                c++;
            }
        }
    }
    cout << c << endl;

    return 0;
}
