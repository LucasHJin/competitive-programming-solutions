#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;

    // each can cover max of 2k+1 -> divide and round up

    vector<int> s2(n+1, 0); // diff array
    
    // make diff array by marking +1 and -1 where the segments start and stop
    for (int i=0; i<n; i++) {
        if (s[i]=='1') {
            int left = max(0, i-k);
            int right = min(n-1, i+k);
            s2[left] += 1;
            if (right+1<n) {
                s2[right+1] -= 1;
            }
        }
    }

    // prefix sum to get actual array
    for (int i=1; i<n; i++) {
        s2[i] += s2[i-1];
    }

    s2.pop_back();
    /* 
    for (auto it: s2) {
        cout << it;
    }
    cout << endl;
     */

    vector<int> uncovered;
    int prev = 1;
    int count = 0;
    for (auto it: s2) {
        if (it>0) {
            if (prev==0) {
                uncovered.push_back(count);
                count = 0;
                prev=1;
            }
        } else {
            prev = 0;
            count++;
        }
    }
    if (prev==0) {
        uncovered.push_back(count);
    }
    /*
    for (auto it: uncovered) {
        cout << it << " ";
    }
    cout << endl;
    */

    int light = 0;
    for (auto it: uncovered) {
        light += ceil((float)it/(2*k+1));
    }

    cout << light << endl;

    return 0;
}
