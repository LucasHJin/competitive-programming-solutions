
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
    int n;
    ll count;
    cin >> n;
    count=0;
    VLL arr;
    FOR(i, 0, n, 1) {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }

    FOR(i, 1, n, 1) {
        while (arr[i]<arr[i-1]) {
            arr[i]+=1;
            count+=1;
        }
    }
    cout << count;



    return 0;
}
