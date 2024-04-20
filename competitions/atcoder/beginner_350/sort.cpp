#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;



int main()
{
    int n;
    cin >> n;
    vector<int> pm;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        pm.push_back(temp);
    }

    int base = 0;
    for (int i=0; i<n; i++) {
        if (pm[i]!=i+1) {
            base = 1;
        }
    }

    if (base == 0) {
        cout << 0;
    } else {
        vector<pair<int, int>> hold;

        for (int i=0; i<n; ++i) {
            if (pm[i]!=i+1) { //if not in right spot
                hold.push_back(make_pair(i+1, pm[i]));
                swap(pm[i], pm[pm[i]-1]); //moving actual value to correct spot -> repeat until you get good value in good spot
                --i; //decrease by 1 in case still need to swap
            }
        }

        cout << hold.size() << endl;
        for (auto it: hold) {
            if (it.first<it.second) {
                cout << it.first << " " << it.second << endl;
            } else {
                cout << it.second << " " << it.first << endl;
            }
        }
    }
    
    return 0;
}