#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n);
    for (int i=0; i<n; i++) {
        cin >> f[i];
    }

    ll total = 0;
    unordered_map<int, int> f_count; //flavor amoutns in current window
    ll distinct = 0;
    int l = 0;
    
    //go through all possible values
    for (int r=0; r<n; r++) {
        //add one more flavor
        if (f_count[f[r]] == 0) { //first time -> add to distinct amount
            distinct++;
        }
        f_count[f[r]]++; //add to number of flavors
        
        //if has at least k distinct
        while (distinct >= k) {
            //if it works from 1 to 3, it works from 1 to n-2, n-1, n...
            total += n - r;
            //decrement current left flavor by 1
            f_count[f[l]]--;
            //if no longer there -> one less distinct
            if (f_count[f[l]] == 0) {
                distinct--;
            }
            l++;
        }
    }
    
    cout << total << endl;



    return 0;
}
