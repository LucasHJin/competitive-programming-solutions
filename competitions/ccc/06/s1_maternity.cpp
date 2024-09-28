#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string mother, father;
    cin >> mother >> father;
    vector<int> alice(5);
    vector<int> bob(5);
    for (int i=0; i<5; i++) {
        for (int j=0; j<2; j++) {
            if (isupper(mother[i*2+j])) {
                alice[i]++;
            }
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<2; j++) {
            if (isupper(father[i*2+j])) {
                bob[i]++;
            }
        }
    }
    /*
    for (auto it: alice) {
        cout << it << " ";
    } cout << endl;
    for (auto it: bob) {
        cout << it << " ";
    } cout << endl;
    */

    int x;
    cin >> x;
    for (int j=0; j<x; j++) {
        string baby;
        cin >> baby;
        bool yes = true;
        for (int i=0; i<5; i++) {
            if (islower(baby[i])) {
                if (alice[i]==2 or bob[i]==2) {
                    yes = false;
                    break;
                }
            } else {
                if (alice[i]==0 and bob[i]==0) {
                    yes = false;
                    break;
                }
            }
        }
        if (yes) {
            cout << "Possible baby." << endl;
        } else {
            cout << "Not their baby!" << endl;
        }
    }
    

    return 0;
}

