#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> hallway(2, vector<char>(n));
    for (int i=0; i<2; i++) {
        string line;
        cin >> line;
        for (int j=0; j<n; j++) {
            int cell = line[j];
            hallway[i][j] = cell;
        }
    }
    int filled = 0;
    for (int i=0; i<n; i++) {
        if (hallway[0][i]=='S' && hallway[1][i]=='S') {
            filled++;
        }
    }

    if (filled<=2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    
    return 0;
}