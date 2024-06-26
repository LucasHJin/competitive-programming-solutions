#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;

        auto lower = lower_bound(x.begin(), x.end(), a);
        auto upper = upper_bound(x.begin(), x.end(), b);
        /*
        Same as:
        int l = 0;
        int r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ages[mid] < a) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int lower = l;

        it will run even after found target value -> until while condition is false
        makes l be the lowest that is greater or equal to the target

        int l = 0;
        int r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ages[mid] <= b) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int upper = l;
        */

        int count = upper - lower;

        cout << count << endl;

    }



    return 0;
}


