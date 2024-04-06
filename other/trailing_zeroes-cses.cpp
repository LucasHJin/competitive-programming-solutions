#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef long long int ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    ll trail=0;
    ll search=5;
    while (search <= n) {
        //doesn't matter if dividing doesn't give int -> rounds down (i.e. 1.3 divisors is just 1)
        trail += n/search;
        search*=5;
    }
    cout << trail;

    return 0;
}