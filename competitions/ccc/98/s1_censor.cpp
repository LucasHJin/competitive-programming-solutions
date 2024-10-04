#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    for (int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            if (word.length()==4) {
                cout << "****";
            } else {
                cout << word;
            }
            cout << " ";
        }
        cout << endl;
    }


    return 0;
}

