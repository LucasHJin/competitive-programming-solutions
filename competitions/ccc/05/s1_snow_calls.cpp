#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    unordered_map<char, int> letterToNumber = {
        {'A', 2}, {'B', 2}, {'C', 2},
        {'D', 3}, {'E', 3}, {'F', 3},
        {'G', 4}, {'H', 4}, {'I', 4},
        {'J', 5}, {'K', 5}, {'L', 5},
        {'M', 6}, {'N', 6}, {'O', 6},
        {'P', 7}, {'Q', 7}, {'R', 7}, {'S', 7},
        {'T', 8}, {'U', 8}, {'V', 8},
        {'W', 9}, {'X', 9}, {'Y', 9}, {'Z', 9}
    };
    for (int x=0; x<t; x++) {
        string phone;
        cin >> phone;
        for (auto it: phone) {
            while (phone.find('-') != string::npos) {
                phone.erase(phone.find('-'), 1);
            }
        }
        string ans = "";
        for (int i=0; i<10; i++) {
            if (i==3 or i==6) {
                ans += '-';
            }
            if (!isdigit(phone[i])) {
                ans += to_string(letterToNumber[phone[i]]);
            } else {
                ans += phone[i];
            }
        
        }

        cout << ans << endl;
    }


    return 0;
}

