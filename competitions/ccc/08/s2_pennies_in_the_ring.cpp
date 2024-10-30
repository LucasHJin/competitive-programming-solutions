#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int x;
    cin >> x;
    while (x!=0) {
        if (x==0) 
            break;
        int cnt = 0;
        //calculate max y value point for each x value and add that (so that it has all those coords)
        for (int i=0; i<=x; i++) {
            cnt += static_cast<int>(sqrt(x*x-i*i));
        }
        //#4 for symmetry, +1 for (0, 0)
        cout << cnt*4+1 << endl;

        cin >> x;
    }


    return 0;
}
