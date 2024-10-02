#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double min = DBL_MAX;
    for (int i=1; i<n-1; i++) {
        double low = abs(v[i-1]-v[i])/2.0;
        double high = abs(v[i]-v[i+1])/2.0;
        if (low+high<min) {
            min = low + high;
        }
    }
    cout << fixed << setprecision(1) << min << endl;



    return 0;
}

