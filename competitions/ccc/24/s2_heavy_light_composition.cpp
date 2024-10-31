#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t >> n;
    for (int i=0; i<t; i++) {
        string seq;
        cin >> seq;
        unordered_map<char, int> mapl;
        for (int i=0; i<n; i++) {
            if (mapl.find(seq[i])==mapl.end()) {
                mapl[seq[i]] = 1;
            } else {
                mapl[seq[i]]++;
            }
        }

        bool good = true;
        string l;
        if (mapl[seq[0]]==1) {
            l = "light";
        } else if (mapl[seq[0]]>1) {
            l = "heavy";
        }
        for (int i=1; i<n; i++) {
            if (l=="light" and mapl[seq[i]]>1) {
                l = "heavy";
            } else if (l=="heavy" and mapl[seq[i]]==1) {
                l = "light";
            } else {
                good = false;
                break;
            }
        }
        if (good) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }

    return 0;
}
