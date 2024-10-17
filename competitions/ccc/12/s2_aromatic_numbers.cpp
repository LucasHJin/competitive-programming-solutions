#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string num;
    cin >> num;
    vector<pair<int, int>> vals;
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    for (int i=0; i<num.size(); i+=2) {
        int a = num[i]-'0';
        int r = m[num[i+1]];
        vals.push_back({a*r, r});
    }

    int ans = 0;
    for (int i=1; i<vals.size(); i++) {
        if (vals[i].second>vals[i-1].second) {
            ans -= vals[i-1].first;
        } else {
            ans += vals[i-1].first;
        }
    }
    ans += vals[vals.size()-1].first;

    cout << ans << endl;


    return 0;
}
