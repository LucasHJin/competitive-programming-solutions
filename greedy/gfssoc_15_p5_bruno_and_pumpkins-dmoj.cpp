#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin >> n >> t;

    vector<int> neg;
    vector<int> pos;

    for (int i=0; i<n; i++) {
        int temp; 
        cin >> temp;
        if (temp<0) {
            neg.push_back(temp);
        }
        if (temp>0) {  
            pos.push_back(temp);   
        }
    }

    //descending
    sort(neg.begin(), neg.end(), greater<int>());
    //ascending
    sort(pos.begin(), pos.end());

    int ans = INT_MAX;
    //answer if only using positive or negative
    if (pos.size()>=t) {
        ans = pos[t-1];
    }
    if (neg.size()>=t) {
        ans = min(ans, abs(neg[t-1]));
    }

    //answer using both
    //all of negative and rest positive
    for (int i=0; i<neg.size(); i++) {
        //how much extra needed
        int extra = t-(i+1);
        if (extra <= 0) {
            //if current iteration of amount taken from negative still more than necessary
            continue;
        }
        //pick up to the i+1th pumpkin and then go back (round trip)
        int dist = 2*abs(neg[i]);
        //pick up the remaining t-i+1 pumpkins from positive
        if (extra-1 < pos.size()) {
            //adding the distance to round trip
            dist += pos[extra-1];
            ans = min(ans, dist);
        }
    }
    //all of positive and rest negative
    for (int i=0; i<pos.size(); i++) {
        int extra = t-(i+1);
        if (extra <= 0) {
            continue; 
        }
        int dist = 2*abs(pos[i]);
        if (extra-1 < neg.size()) {
            dist -= neg[extra-1];
            ans = min(ans, dist);
        }
    }

    cout << ans << endl;


    return 0;
}

