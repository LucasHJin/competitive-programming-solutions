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
    //combinatorics
    int n;
    cin >> n;
    VLL hold;
    ll subtract, total;
    subtract = 0;
    for (ll i=1; i<=n; i++) {
        total=0;
        //combinatorics of choosing 2 spots - pattern of multiple of eights - xC2
        if (i==1) {
            hold.push_back(0);
        } else {
            total = (((i*i)*(i*i-1))/2)-subtract;
            subtract=subtract+(8*(i-1));
            hold.push_back(total);
        }
        
    }
    for (auto it: hold) {
        cout << it << endl;
    }
 
    return 0;
}