#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

bool compare1(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first > b.first;
}

bool compare2(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
}

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<pair<ll, ll>> ab(n);
    for (int i=0; i<n; i++) {
        cin >> ab[i].first; 
    }
    for (int i=0; i<n; i++) {
        cin >> ab[i].second; 
    }
    
    
    if (x>y) {
        sort(ab.begin(), ab.end(), compare2);
    } else {
        sort(ab.begin(), ab.end(), compare1);
    }
    
    /*
    for (int i=0; i<n; i++) {
        cout << ab[i].first << " " << ab[i].second << endl; 
    }
    */
    
    
    ll sum_x = 0;
    ll sum_y = 0;
    ll count = 0;
    
    while (sum_x<=x and sum_y<=y and count!=n) {
        sum_x += ab[count].first;
        sum_y += ab[count].second;
        count += 1;
    }
    
    cout << count << endl;
    
    

    return 0;
}