#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cin.ignore(); //ignore new line so that it reads the actual first line with getline
    ll t = 0;
    ll s = 0;
    for (int i=0; i<n; i++) {
        string phrase;
        getline(cin, phrase); //for getting entire line
        for (auto it: phrase) {
            if (it=='t' or it=='T') {
                t++;
            } else if (it=='s' or it=='S') {
                s++;
            }
        }
    }
    if (t>s) {
        cout << "English" << endl;
    } else {
        cout << "French" << endl;
    }


    return 0;
}

