#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int x=0; x<t; x++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            int aa;
            cin >> aa;
            a[i] = aa-1;
        }
        bool good = true;
        vector<bool> filled(n, false);

        filled[a[0]] = true;

        for (int i=1; i<n; i++) {
            bool temp = false;
            if (a[i]-1>=0) {
                if (filled[a[i]-1]) {
                    temp = true;
                }
            }
            if (a[i]+1<n) {
                if (filled[a[i]+1]) {
                    temp = true;
                }
            }
            if (!temp) {
                good = false;
                break;
            }
            filled[a[i]] = true;
        }

        if (good) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }
}

