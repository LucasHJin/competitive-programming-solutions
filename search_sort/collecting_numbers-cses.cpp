#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> ind(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    int turns = 1;

    for (int i=0; i<n; i++) {
        ind[x[i]] = i;
    }

    //check each number -> if next comes before, need another turn, else don't need another turn
    for (int i=1; i<n; i++) {
        if (ind[i+1] < ind[i])
            turns++;
    }

    cout << turns << endl;
    

    return 0;
    
} 