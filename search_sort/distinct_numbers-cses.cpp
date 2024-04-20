#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;



int main()
{
    int n;
    cin >> n;
    set<ll> hold;
    for (int i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        hold.insert(temp);
    }
    cout << hold.size() << endl;

    
    return 0;
}