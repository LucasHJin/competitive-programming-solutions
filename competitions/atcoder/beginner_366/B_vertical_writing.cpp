#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    int m = 0;
    for (auto str: s) {
        m = max(m, static_cast<int>(str.size()));
    }

    vector<string> result(m, string(n, '*'));

    for (int i=0; i<n; i++) {
        string str = s[i];
        int pos = n - i - 1;  
        int length_str = str.size();
        
        for (int j=0; j<length_str; j++) {
            result[j][pos] = str[j];
        }
        
        for (int j=length_str; j<m; j++) {
            result[j][pos] = '*';
        }
    }

    for (auto& str: result) {
        while (!str.empty() and str.back() == '*') {
            str.pop_back();
        }
    }

    for (auto str: result) {
        cout << str << endl;
    }

    
    return 0;
}

