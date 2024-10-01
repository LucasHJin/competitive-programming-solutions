#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string a, b;
    cin >> a >> b;

    unordered_map<char, int> am, bm;
    int star_count = 0;

    for (char ch : a) {
        am[ch]++;
    }

    for (char ch : b) {
        if (ch == '*') {
            star_count++;
        } else {
            bm[ch]++;
        }
    }

    bool good = true;
    int excess_chars_needed = 0;

    for (auto entry : am) {
        char ch = entry.first;
        int count_in_a = entry.second;
        int count_in_b = bm[ch];

        if (count_in_a > count_in_b) {
            excess_chars_needed += (count_in_a-count_in_b);
        }
    }

    if (excess_chars_needed > star_count) {
        good = false;
    }

    if (good) {
        cout << "A" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}

