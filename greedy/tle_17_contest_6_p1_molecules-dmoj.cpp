#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> freq(26);
    if (n%2==1) {
        cout << "No" << endl;
    } else {
        for (char c : str) {
            freq[c-'a']++; //the char acts as ASCII values -> i.e. b-a = 98-97 = 1
        }

        int max_f = *max_element(freq.begin(), freq.end()); //* gives value at iterator

        if (max_f<=n/2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
    return 0;
}

