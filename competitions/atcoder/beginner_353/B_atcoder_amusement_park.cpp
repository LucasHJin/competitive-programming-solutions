#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int count = 0;
    int temp = k;

    for (int i=0; i<n; i++) {
        if (temp>=a[i]) {
            temp-=a[i];
        } else {
            i-=1;
            count+=1;
            temp = k;
        }
    }

    cout << count+1 << endl;

    return 0;
} 