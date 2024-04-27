#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

//lower bound: https://cplusplus.com/reference/algorithm/upper_bound/
//multiset: https://cplusplus.com/reference/set/multiset/

int main() {

    int n, m;
    cin >> n >> m;
    multiset<int> price;
    vector<int> pay(m);
    
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        price.insert(temp);
    }

    for (int i=0; i<m; i++) {
        cin >> pay[i];
    }


    for (int i=0; i<m; i++) {
        int max = pay[i];
        auto it = price.upper_bound(max); 
        
        if (it==price.begin()) {
            cout << -1 << endl; 
        } else {
            --it; 
            cout << *it << endl; //* -> thing at index
            price.erase(it); 
        }
    }
    
    return 0;
}