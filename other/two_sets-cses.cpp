#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
 
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef vector<VI> VVI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef long double ld;
 
 
int main() {
    ll n;
    cin >> n;
    VLL first;
    VLL sec;
    if (n%4==0 or n%4==3) {
        cout << "YES" << endl;
        if (n%4==3) {
            //odd case
            ll half=(n*(n+1)/2)/2;
            ll sum1=0;
            ll max=n;
            VLL moved(n, 0);
            while (sum1 < half) {
                if ((half-sum1) > max) {
                    first.push_back(max);
                    moved[max-1]=1;
                    sum1+=max;
                    max--;
                } else {
                    first.push_back(half-sum1);
                    moved[half-sum1-1]=1;
                    break;
                }
            }
            for (ll i=0; i<n; i++) {
                if (moved[i]==0) {
                    sec.push_back(i+1);
                }
            }
            cout << first.size() << endl;
            for (auto it: first) {
                cout << it << " ";
            }
            cout << "\n" << sec.size() << endl;
            for (auto it: sec) {
                cout << it << " ";
            }
        } else {
            //even case
            for (ll i=1; i<=(n/4); i++) {
                first.push_back(i);
                first.push_back(n-i+1);
            }
            for (ll i=(n/4)+1; i<=(n-n/4); i++) {
                sec.push_back(i);
            }
            cout << first.size() << endl;
            for (auto it: first) {
                cout << it << " ";
            }
            cout << "\n" << sec.size() << endl;
            for (auto it: sec) {
                cout << it << " ";
            }
        }
    } else {
        cout << "NO";
    }
 
    return 0;
}