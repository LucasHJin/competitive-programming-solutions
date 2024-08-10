#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, t, a;
    cin >> n >> t >> a;
    int temp = n+1;
    temp = temp/2;

    if (t>=temp or a>=temp) {
        cout << "Yes" << endl;
    }  else {
        cout << "No" << endl;
    }
    


    return 0;
}

