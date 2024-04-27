#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> balls;
    vector<ll> seq;
    for (ll i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        balls.push_back(temp);
    }

    for (ll i=0; i<n; i++) {
        /*
        for (auto it: seq) {
            cout << it << " ";
        } 
        cout << endl;
        */
        
        ll ball = balls[i];
        seq.push_back(ball);

        while (seq.size()>1 and (seq[seq.size()-1] == seq[seq.size()-2])) {
            ll last = seq.back();
            seq.pop_back(); //first
            seq.pop_back(); //second
            ll add = last+1; //new = sum of prev two (add 1 to exponents)
            seq.push_back(add);
        }
    }
    /*
    for (auto it: seq) {
            cout << it << " ";
        } 
        cout << endl;
    */
    
    cout << seq.size() << endl;
    
    return 0;
}