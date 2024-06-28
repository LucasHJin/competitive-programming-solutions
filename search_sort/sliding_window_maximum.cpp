#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    deque<int> window;
    int n, k;
    cin >> n >> k;
    vector<int> elements(n);
    for (int i=0; i<n; i++) {
        cin >> elements[i];
    }

    for (int i=0; i<n; i++) {
        //removing items from the front if smaller than current element (guarenteed not max)
        while (!window.empty() and elements[i]>window.front()) {
            window.pop_front();
        }

        //removing items from the back if they are from a previous iteration
        if (i>=k and elements[i-k]==window.back()) {
            window.pop_back();
        }

        //adding new item to front
        window.push_front(elements[i]);
        
        //if k items have been added -> start printing out maxes
        if (i >= k-1) {
            cout << window.back() << " ";
        }
        
    }

    return 0;
}

