#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int binary_search(ll t, int pos_size, vector<ll> pos) {
    int l = 0, r = pos_size-1;
    int ans = pos_size;
    while (l<=r) {
        int mid = (l+r)/2;
        if (pos[mid]>=t) {
            ans = mid;
            r = mid-1;
        } 
        else if (pos[mid]<t) {
            l = mid+1;
        }
    }
    //number of elements from greater position to end of vector (amount passed)
    return pos_size-ans;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s; //1 pos, 0 neg

    vector<ll> pos;
    vector<ll> neg;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        if (s[i]=='1') {
            pos.push_back(temp);
        } else {
            neg.push_back(temp);
        }
    }
    
    ll count = 0;
    for (int i: neg) {
        //neg goes t backwards and pos goes t forwards -> max distance is i-2*t
        ll tar = i-(2*t);
        //must be greater than i (or else starts past it)
        count += binary_search(tar, pos.size(), pos)-binary_search(i, pos.size(), pos);
    }

    cout << count << endl;


    return 0;
}

