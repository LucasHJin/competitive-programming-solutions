#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;

struct Change {
    int ind;     
    char curr;  
    char tar; 

    int diff() const {
        return tar - curr;
    }

    bool operator<(const Change& other) const {
        if (diff() == other.diff()) {
            return ind < other.ind;
        }
        return diff() < other.diff();
    }
};


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    string t;
    cin >> s;
    cin >> t;

    vector<string> ans;

    vector<Change> neg;
    vector<Change> pos;

    for (int i=0; i<s.length(); i++) {
        if (s[i]!=t[i]) {
            if (s[i]-t[i]>0) {
                pos.push_back(Change{i, s[i], t[i]});
            } else {
                neg.push_back(Change{i, s[i], t[i]});
            }
        }
    }

    sort(pos.begin(), pos.end(), [](const Change& a, const Change& b) {
        return a.ind < b.ind;
    });

    sort(neg.begin(), neg.end(), [](const Change& a, const Change& b) {
        return a.ind > b.ind;
    });

    
    for (auto it: pos) {
        s[it.ind] = t[it.ind];
        ans.push_back(s);
    }

    for (auto it: neg) {
        s[it.ind] = t[it.ind];
        ans.push_back(s);
    }

    cout << ans.size() << endl;
    for (auto it: ans) {
        cout << it << endl;
    }

    return 0;
}