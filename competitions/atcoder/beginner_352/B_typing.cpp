#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    vector<int> hold;

    int counter = 0;

    for (int i=0; i<t.size(); i++) {
        if (s[counter]==t[i]) {
            hold.push_back(i+1);
            counter+=1;
        } 
    }
    
    for (auto it: hold) {
        cout << it << " ";
    }

    return 0;
}
