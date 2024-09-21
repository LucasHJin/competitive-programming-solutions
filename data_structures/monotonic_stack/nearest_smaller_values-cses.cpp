#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;


//Use pair whenever need to write actual index instead of value

int main() {
    stack<pair<int, int>> sta;
    int n;
    cin >> n;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        while (!sta.empty() and sta.top().first>=x) {
            sta.pop();
        }

        if (sta.empty()) {
            cout << 0 << " ";
        } else {
            cout << sta.top().second << " ";
        }

        sta.push({x, i+1});
    }


    return 0;
}


