#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> tides(n);
    for (int i=0; i<n; i++) {
        cin >> tides[i];
    }

    sort(tides.begin(), tides.end());

    if (n%2==0) {
        int mid = n/2;
        auto high = vector<int>(tides.begin()+mid, tides.end());
        auto low = vector<int>(tides.begin(), tides.begin()+mid);
        reverse(low.begin(), low.end());

        for (int i=0; i<high.size(); i++) {
            cout << low[i] << " " << high[i] << " ";
        }
    } else {
        int mid = (n-1)/2;  
        auto high = vector<int>(tides.begin()+mid+1, tides.end());
        auto low = vector<int>(tides.begin(), tides.begin()+mid);
        reverse(low.begin(), low.end());

        cout << tides[mid] << " ";

        for (int i=0; i<high.size(); i++) {
            cout << high[i] << " " << low[i] << " ";
        }
    }

    return 0;
}
