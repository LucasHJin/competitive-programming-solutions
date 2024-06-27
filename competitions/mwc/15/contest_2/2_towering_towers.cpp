#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int h;
    stack<pair<int, int>> tower_stack;
    for (int i=0; i<n; i++) {
        cin >> h;
        /*
        while (!tower_stack.empty()) {
            cout << tower_stack.top().first << " " << tower_stack.top().second << endl;
            tower_stack.pop();
        }
        */

        //need <= instead of < because can see past buildings that are same height
        while (!tower_stack.empty() and tower_stack.top().first<=h) {
            tower_stack.pop();
        }

        if (tower_stack.empty()) {
            cout << i << " ";
        } else {
            cout << i - tower_stack.top().second << " ";
        }

        tower_stack.push({h, i});
    }


    return 0;
}


