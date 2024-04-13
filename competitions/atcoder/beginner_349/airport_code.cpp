#include <bits/stdc++.h>
#include <iostream>
#include <cctype>
 
typedef long long ll;
 
using namespace std;
 
int main()
{
    string S;
    string T;
    cin >> S >> T;
    
    vector<int> l1;
    vector<int> l2;
    vector<int> l3;
    
    
    for (int i=0; i<S.size(); i++) {
        if (S[i]==tolower(T[0])) {
            l1.push_back(i);
        }
    }
    
    for (int i=0; i<S.size(); i++) {
        if (S[i]==tolower(T[1])) {
            l2.push_back(i);
        }
    }

    if (T[2]!='X') {
        for (int i=0; i<S.size(); i++) {
            if (S[i]==tolower(T[2])) {
                l3.push_back(i);
            }
        }
    }
    
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    sort(l3.begin(), l3.end());
    
    
    if (T[2]!='X') {
        for (int i : l1) {
            for (int j : l2) {
                for (int k : l3) {
                    if (i < j && j < k) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    } else {
        if (T[2] == 'X') {
            for (int i : l1) {
                for (int j : l2) {
                    if (i < j) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "No" << endl;
    
    return 0;
}