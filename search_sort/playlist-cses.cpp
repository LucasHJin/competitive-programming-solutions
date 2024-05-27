#include <bits/stdc++.h>
#include <iostream>
#include <map>
 
typedef long long ll;
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> k(n);
    map<int, int> longest;
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }
    
    int lss = 0;
    int l = 0;
    
    for (int r=0; r<n; r++) { 
        if (longest.find(k[r]) == longest.end()) //element not in
            //longest.insert(k[r], r);
            longest[k[r]] = r;
        else { //term is in map
            if (longest[k[r]] >= l) //term is inside current window (because not removing any terms)
                l = longest[k[r]] + 1; //move to term just after it
            longest[k[r]] = r; //add the term
        }
 
        
        if (r-l+1 > lss) {
            lss = r-l+1; //compare size
        }
    }
    
    cout << lss << endl;
    
 
    return 0;
    
