#include <map>
#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
int main()
{
    string n;
    cin >> n;
    map<char, int> values;
    map<int, int> good;
    
    for (int i=0; i<n.size(); i++) {
        if (values.find(n[i]) != values.end()) {
            values[n[i]]++;
        } else {
            values[n[i]] = 1;
        }
    }
    
    for (auto pair: values) {
        if (good.find(pair.second) != good.end()) {
            good[pair.second]++;
        } else {
            good[pair.second] = 1;
        }
    }

    
    int a=1;
    
    for (auto pair: good) {
        if (pair.second!=2) {
            cout << "No" << endl;
            a+=1;
            break;
        }
    }
    
    
    if (a==1) {
        cout << "Yes" << endl;
    }
    
    
    
    
    return 0;
}