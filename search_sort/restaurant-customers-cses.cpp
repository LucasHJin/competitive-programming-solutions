#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;

int main() {
    int n;
    cin >> n;
    int max = -100000;
    int count = 0;

    map<int, char> times;
    vector<int> a(n);
    vector<int> b(n);

    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i=0; i<n; i++) {
        times[a[i]]='a';
    }
    for (int i=0; i<n; i++) {
        times[b[i]]='b';
    }

    for (auto it: times) {
        if (it.second == 'a') {
            count+=1;
            if (max<count) {
                max=count;
            }
        } else {
            count-=1;
        }
    }

    cout << max << endl;




    return 0;
}