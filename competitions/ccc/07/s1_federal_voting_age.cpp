#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int y, m, d;
        cin >> y >> m >> d;
        if (y<1989) {
            cout << "Yes" << endl;
        } else if (y==1989) {
            if (m<2) {
                cout << "Yes" << endl;
            } else if (m==2) {
                if (d<=27) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}

