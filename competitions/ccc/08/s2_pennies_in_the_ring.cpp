#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int x;
    cin >> x;
    while (x!=0) {
        int c = 8;
        int ans = 5;
        bool yes = true;
        while (x>1) {
            ans+=c;
            if (yes) {
                c+=8;
                yes=false;
            } else {
                c+=4;
                yes=true;
            }
            x--;
        }
        cout << ans << endl;

        cin >> x;
    }


    return 0;
}
