#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> sum(m);

    for(int i=0; i<m; i++) {
        cin >> a[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int temp;
            cin >> temp;
            sum[j] += temp;
        }
    }

    int good = 0;
    for (int i=0; i<m; i++) {
        if (sum[i]<a[i]) {
            good = 1;
            break;
        }
    }

    if (good==1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }


 
    return 0;
    
}