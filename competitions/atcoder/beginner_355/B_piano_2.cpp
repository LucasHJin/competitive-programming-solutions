#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int q = 0;
    int j = 0;
    int i = 0;
    int last = -10;

    for (int k=0; k<n+m; k++) {
        //cout << i << " " << j << endl;
        if (i >= n) {
            break;
        }

        if (j >= m) {
            //no more b -> must be a
            if (last == 0) {
                q = 1;
                break;
            }
            last = 0;
            i++;
        } else if (a[i] > b[j]) {
            j++;
            last = 1;
        } else if (a[i] < b[j]) {
            if (last == 0) {
                q = 1;
                break;
            }
            i++;
            last = 0;
        }
    }

    if (q==1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    
    return 0;
    
} 