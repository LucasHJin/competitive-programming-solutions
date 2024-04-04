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
    ll n;
    VLL list;
    cin >> n;
    list.push_back(n);
    while (n!=1) {
        if (n%2==1) {
            n=n*3+1;
        } else {
            n=n/2;
        }
        list.push_back(n);
    }
    for (auto i: list) {
        cout << i << ' ';
    }

    return 0;
}
