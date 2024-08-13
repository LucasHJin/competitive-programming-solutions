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
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<string> s(m);
        for (int i=0; i<m; i++) {
            cin >> s[i];
        }

        for (int i=0; i<m; i++) {
            unordered_map<char, int> cN;
            unordered_map<int, char> nC;
            string st = s[i];
            bool good = true;

            if (st.size() != n) {
                good = false;
            } else {
                for (int j=0; j<st.size(); j++) {
                    char c = st[j];
                    int num = a[j];

                    if (cN.count(c) and cN[c] != num) {
                        good = false;
                        break;
                    }
                    if (nC.count(num) and nC[num] != c) {
                        good = false;
                        break;
                    }

                    cN[c] = num;
                    nC[num] = c;
                }
            }

            if (good) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }


    }
}

