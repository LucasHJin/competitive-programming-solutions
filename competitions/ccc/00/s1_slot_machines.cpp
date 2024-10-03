#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    int f, s, t;
    cin >> f >> s >> t;
    int c = 0;
    while (q>0) {
        q--;
        if (c%3==0) {
            f++;
            if (f==35) {
                q+=30;
                f=0;
            }
        } else if (c%3==1) {
            s++;
            if (s==100) {
                q+=60;
                s=0;
            }
        } else {
            t++;
            if (t==10) {
                q+=9;
                t=0;
            }   
        }
        c++; 
    }
    cout << "Martha plays " << c << " times before going broke." << endl;

    return 0;
}

