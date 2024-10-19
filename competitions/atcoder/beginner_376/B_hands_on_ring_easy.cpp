#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

bool is_between(int a, int b, int c) {
    if (a < b) {
        return a < c && c < b;
    } else {
        return c > a || c < b;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    //vector<pair<int, int>> move(q);
    int l=1;
    int r=2;
    int ans=0;
    for (int i=0; i<q; i++) {
        char h;
        int t;
        cin >> h >> t;
        //move[i] = {h, t};

        if (h == 'R') { 
            if (r != t) { 
                int cw = (t - r + n) % n;
                int ccw = (r - t + n) % n;
                
                if (!is_between(l, r, t)) {
                    ans += cw;
                } else {
                    ans += ccw;
                }

                r = t;
            }
        } else {  
            if (l != t) { 
                int cw = (t - l + n) % n;
                int ccw = (l - t + n) % n;

                if (!is_between(r, l, t)) {
                    ans += cw;
                } else {
                    ans += ccw; 
                }

                l = t;
            }
        }
    }
    cout << ans << endl;


    
    return 0;
}
