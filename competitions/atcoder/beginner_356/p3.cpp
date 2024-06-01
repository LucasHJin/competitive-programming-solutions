#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> c(m);
    vector<char> r(m);
    vector<vector<int>> a(m);

    for (int i=0; i<m; i++) {
        cin >> c[i];
        a[i].resize(c[i]);
        for (int j=0; j<c[i]; j++) {
            cin >> a[i][j];
        }
        cin >> r[i];
    }

    int good = 0;

    //go through all combinations -> n<15 (no TLE)
    //combination in bits
    for (int comb=0; comb<(1 << n); comb++) {
        // 1<<n gives 2^n
        bool valid = true;
        for (int i=0; i<m and valid; i++) {
            int cnt = 0;
            //num real keys current
            for (int j=0; j<c[i]; j++) {
                if (comb & (1 << (a[i][j] - 1))) {
                    //bitwise and -> comb & (1 << (a[i][j] - 1))
                    //comparing real keys within the combination to the ones found in the put in keys
                    cnt++;
                }
            }
            //check from test result
            if ((r[i]=='o' and cnt<k) or (r[i]=='x' and cnt>=k)) {
                //if it opened but there aren't enough keys in this combination
                //or it didn't open but there are enough keys
                valid = false;
            }
        }

        //if it worked
        if (valid) {
            good++;
        }
    }

    cout << good << endl;

    return 0;
}


