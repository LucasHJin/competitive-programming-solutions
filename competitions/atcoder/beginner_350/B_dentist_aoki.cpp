#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;


int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> t;
    map<int, int> vs;

    for (int i=0; i<q; i++) {
        int temp;
        cin >> temp;
        t.push_back(temp);
    }

    for (int i=0; i<q; i++) {
        if (vs.find(t[i]) != vs.end()) {
            vs[t[i]]++;
        } else {
            vs[t[i]] = 1;
        }
    }

    int tt = n;
    
    for (const auto& pair: vs) {
        if (pair.second%2==1) {
            tt-=1;
        }
    }
    cout << tt << endl;

    return 0;
}