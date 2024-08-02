#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n;
    k=0;

    ll temp;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        k = max(k, temp);
    }

    if (k>=10000) {
        cout << "Something is wrong with these cuteness values" << endl;
    } else if (k>1000 and k<10000) {
        cout << "Cuteness by definition is similarity to Cactus" << endl;
    } else {
        cout << "Cuteness by definition is similarity to Carol" << endl;
    }



    
    return 0;
}

