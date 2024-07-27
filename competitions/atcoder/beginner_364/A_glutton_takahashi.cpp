#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string prev, curr;
    cin >> prev;
    
    bool can = true;
    
    for (int i=0; i<n-1; i++) {
        cin >> curr;
        if (prev == "sweet" and curr == "sweet" and i != n-2) {
            can = false;
        } 
        prev = curr;
    }
    
    if (can) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}