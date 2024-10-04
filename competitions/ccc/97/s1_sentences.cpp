#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int x=0; x<n; x++) {
        int s, v, o;
        cin >> s >> v >> o;
        vector<string> sl;
        vector<string> vl;
        vector<string> ol;
        cin.ignore(); //use before getline if used cin
        for (int i=0; i<s; i++) {
            string temp;
            getline(cin, temp);
            sl.push_back(temp);
        }
        for (int i=0; i<v; i++) {
            string temp;
            getline(cin, temp);
            vl.push_back(temp);
        }
        for (int i=0; i<o; i++) {
            string temp;
            getline(cin, temp);
            ol.push_back(temp);
        }

        vector<string> ans;
        for (auto it: sl) {
            for (auto it2: vl) {
                for (auto it3: ol) {
                    string a = it + " " + it2 + " " + it3 + ".\n";
                    ans.push_back(a);
                }
            }
        }
        for (auto it: ans) {
            cout << it << endl;
        }
    }


    return 0;
}

