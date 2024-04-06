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
    int n;
    cin >> n;
    ll result=1.0;
    for (int i=1; i<=n; i++) {
        result=(result*2)%1000000007;
    }
    cout << result;

    return 0;
}