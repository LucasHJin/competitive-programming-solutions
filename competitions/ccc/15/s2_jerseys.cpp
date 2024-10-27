#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int j, a;
    cin >> j;
    cin >> a;
    vector<int> js;
    vector<pair<int, int>> as;
    for (int i=0; i<j; i++) {
        char size;
        cin >> size;
        if (size=='S') {
            js.push_back(0);
        } else if (size=='M') {
            js.push_back(1);
        } else {
            js.push_back(2);
        }
    }
    for (int i=0; i<a; i++) {
        char size;
        cin >> size;
        int num;
        cin >> num;
        if (size=='S') {
            as.push_back({0, num});
        } else if (size=='M') {
            as.push_back({1, num});
        } else {
            as.push_back({2, num});
        }
    }

    int c = 0;
    for (auto it: as) {
        if (it.first<=js[it.second-1]) {
            c++;
            js[it.second-1] = -1;
        }
    }
    cout << c << endl;


    return 0;
}
