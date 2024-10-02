#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> sw;
    vector<int> se;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        sw.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        se.push_back(temp);
    }

    int day = 0;
    ll v1 = 0;
    ll v2 = 0;
    for (int i=0; i<n; i++) {
        v1+=sw[i];
        v2+=se[i];
        if (v1==v2) {
            day = i+1;
        }
    }
    cout << day << endl;


    return 0;
}

