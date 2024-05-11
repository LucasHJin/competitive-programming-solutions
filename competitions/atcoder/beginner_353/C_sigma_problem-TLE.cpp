#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll sum=0;
    int i = 0;
    int j = i+1;
    while (i<n-1) {
        ll temp = (a[i]+a[j]) % 100000000;
        sum += temp;
        j++;

        if (j==n) {
            i++;
            j = i+1;
        }
    } 

    cout << sum << endl;

    return 0;
} 