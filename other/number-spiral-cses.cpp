#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
 
using namespace std;
 
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef long double ld;
 
 
int main() {
    ll value, n;
    cin >> n;
    VLL hold;
    FOR(i, 0, n, 1) {
        ll x, y;
        cin >> y >> x;
        //if y<=x
        if (y<=x) {
            value=(x-1)*(x-1);
            //then check if x is even or odd -> if even, starting at top, else starting at side
            if (x%2==0) {
                value+=y;
            } else {
                value=value+(2*x-1)-(y-1);
            }
        } else {
            value=(y-1)*(y-1);
            //same as previous, just flip variables
            if (y%2==1) {
                value+=x;
            } else {
                value=value+(2*y-1)-(x-1);
            }
        }
        hold.PB(value);
    }
 
    //print vector
    for (ll i=0; i<n; i++) {
        cout << hold[i] << endl;
    }
 
    return 0;
}