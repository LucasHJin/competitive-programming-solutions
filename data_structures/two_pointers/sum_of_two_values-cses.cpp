#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> vals(n);
    vector<int> copy;
   
    for (int i=0; i<n; i++) {
        cin >> vals[i];
    }
   
    copy = vals;
   
    sort(vals.begin(), vals.end());
   
    int i=0;
    int j=n-1;
    int sum=0;
    while (i<j) { //don't need to check any other values -> if too small, no point in checking other j values because will still be too small
        sum=vals[i]+vals[j];
        if (sum==x) {
            break;
        } else if (sum<x) {
            i++;
        } else {
            j--;
        }
    }
       
    //need to check if find same value -> erase index find and then find the next index possible index
    if (sum==x) {
        auto it1 = find(copy.begin(), copy.end(), vals[i]);
        auto it2 = find(copy.begin(), copy.end(), vals[j]);
        if (it1==it2) {
            copy.erase(it1);
            auto it2 = find(copy.begin(), copy.end(), vals[j]);
            if (it1<it2) {
                cout << it1-copy.begin()+1 << " " << it2-copy.begin()+2 << endl;
            }
            else {
                cout << it2-copy.begin()+1 << " " << it1-copy.begin()+2 << endl;
            }
        } else {
            if (it1<it2) {
                cout << it1-copy.begin()+1 << " " << it2-copy.begin()+1 << endl;
            }
            else {
                cout << it2-copy.begin()+1 << " " << it1-copy.begin()+1 << endl;
            }
        }
    } else {    
        cout << "IMPOSSIBLE" << endl;
    }
   
 
    return 0;
   
}