#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

bool hasDistinct(int y) {
    unordered_set<char> seen;
    string y2 = to_string(y);
    for (int i=0; i<y2.size(); i++) {
        if (seen.find(y2[i]) != seen.end()) {
            return false;
        }
        seen.insert(y2[i]);
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int y;
    cin >> y;
    
    while (!hasDistinct(++y)) { //++y instead of y++ so that it increments first before checking
    }

    cout << y << endl;

    return 0;
}

