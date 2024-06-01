#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;
 

bool stackComp(const stack<int>& s1, const stack<int>& s2) {
    if (s1.empty()) return false; 
    if (s2.empty()) return true; 
    return s1.top() < s2.top();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> k(n);
    vector<stack<int>> am;

    for (int i=0; i<n; i++) {
        cin >> k[i];
    }

    /*
    for (int i=0; i<n; i++) {
        bool inserted = false;
        for (auto& s: am) {
            if (!s.empty() and k[i]<s.top()) {
                s.push(k[i]);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            stack<int> temp;
            temp.push(k[i]);
            am.push_back(temp);
        }
    }
    */

    for (int i = 0; i < n; i++) {
        //left right index binary search
        int l = 0, r = am.size() - 1;
        int sInd = -1;
        //binary search -> find lowest good stack to insert (if none, it is -1)
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (k[i] < am[mid].top()) {
                sInd = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        //if no good stack -> create a new stack
        if (sInd == -1) {
            stack<int> newStack;
            newStack.push(k[i]);
            am.push_back(newStack);
        } else {
            //add to the good stack
            stack<int>& selectedStack = am[sInd];
            selectedStack.push(k[i]);
        }
    }

    cout << am.size() << endl;
    
    return 0;
}
