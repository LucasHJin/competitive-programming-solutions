#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<char> ans(n);
    int c=0;
    for (int i=0; i<n; i++) {
        cin >> ans[i];
    }
    for (int i=0; i<n; i++) {
        char temp;
        cin >> temp;
        if (temp == ans[i]) {
            c++;
        }
    }
    cout << c << endl;
     

    return 0;
}
