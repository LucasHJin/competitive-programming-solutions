#include <bits/stdc++.h>
#include <iostream>
#include <set>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> order;
    ll sum = 0;

    for (int i=0; i<n; i++) {
        string temp;
        int temp2;
        cin >> temp >> temp2;
        order.insert(temp);
        sum += temp2;
    }

    int val = sum % n;
    

    int count = 0;
    for (auto it: order) {
        if (count == val) {
            cout << it << endl;
            break;
        }
        count += 1;
    }


    return 0;
} 