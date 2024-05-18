#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> cards;
    for (int i=0; i<n; i++) {
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        temp.push_back(i+1);
        cards.push_back(temp);
    }

    sort(cards.begin(), cards.end());

    vector<int> good;

    for (int i=0; i<n; i++) {
        good.push_back(i+1);
    }

    int prev_max = cards[0][1];
    int prev_num = cards[0][2];
    vector<int> bad;
    
    int sec_max = -1;
    int sec_num = -1;

    for (int i=0; i<n; i++) {
        if (cards[i][1]<prev_max) {
            bad.push_back(prev_num);
            if (sec_max==-1) {
                prev_max = cards[0][1];
                prev_num = cards[0][2];
            } else {
                prev_max = sec_max;
                prev_num = sec_num;
            }
            i-=1;
        } else {
            sec_max = prev_max;
            sec_num = prev_num;
            prev_max = cards[i][1];
            prev_num = cards[i][2];
        }
    }

    vector<int> third;
    int j=0;
    if (bad.empty()) {
        cout << good.size() << endl;
        for (auto it: good) {
            cout << it << " ";
        }
    } else {
        for (int i=0; i<n; i++) {
            if (good[i]!=bad[j]) {
                third.push_back(good[i]);
            } else {
                j+=1;
            }
        }
        cout << third.size() << endl;
        for (auto it: third) {
            cout << it << " ";
        }
    }
    

    return 0;
    
} 