#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int x=0; x<n; x++) {
        int c;
        cin >> c;
        vector<pair<int, int>> multiples;
        for (int j=1; j*j<=c; j++) {
            if (c%j==0) {
                multiples.push_back({j, c/j});
            }
        }

        bool g = false;
        for (int i=0; i<multiples.size(); i++) {
            for (int j=i; j<multiples.size(); j++) {
                if (i!=j) {
                    if (abs(multiples[i].first+multiples[i].second)==abs(multiples[j].first-multiples[j].second)
                    or abs(multiples[i].first-multiples[i].second)==abs(multiples[j].first+multiples[j].second)) {
                        g = true;
                    }
                }
            }
        }
        if (g) {
            cout << c << " is nasty" << endl;
        } else {
            cout << c << " is not nasty" << endl;
        }
    }

    return 0;
}
