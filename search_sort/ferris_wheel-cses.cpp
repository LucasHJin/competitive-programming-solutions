#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;


int main() {

    int n, x;
    cin >> n >> x;
    vector<int> p(n);

    for (int i=0; i<n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int i = 0;
    int j = n-1;
    int count = 0;

    while(i<=j) {
        int total = p[i]+p[j];
        if (total<=x) {
            count+=1;
            i+=1;
            j-=1;
        } else if (total>x) {
            count+=1; 
            j-=1; //need to always get smaller, getting bigger never smaller than weight -> so can't add to i
        }
    }

    cout << count << endl;
    
    return 0;
}