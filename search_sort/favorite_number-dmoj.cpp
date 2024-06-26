#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> fav(n);
    for (int i=0; i<n; i++) {
        cin >> fav[i];
    }
    sort(fav.begin(), fav.end());
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int given;
        cin >> given;
        auto val_ind = lower_bound(fav.begin(), fav.end(), given);
        int num = *val_ind;
        cout << num << " ";

        //don't need extra +1 because it returns value after the last value of num for upper
        int count = upper_bound(fav.begin(), fav.end(), num) - lower_bound(fav.begin(), fav.end(), num);
        cout << count << endl;
    }


    return 0;
}


