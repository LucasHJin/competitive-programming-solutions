#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int c;
    cin >> c;
    vector<int> t;
    vector<int> t2;
    int B = 0;
    for (int i=0; i<c; i++) {
        int temp;
        cin >> temp;
        if (temp==1) {
            B++;
        }
        t.push_back(temp);
    }
    for (int i=0; i<c; i++) {
        int temp;
        cin >> temp;
        if (temp==1) {
            B++;
        }
        t2.push_back(temp);
    }

    int ans = B*3;
    for (int i=0; i<c; i++) {
        if (i!=c-1) {
            if (t[i]==1 and t[i+1]==1) {
                ans-=2;
            }
            if (t[i]==1 and t2[i]==1 and i%2==0) {
                ans-=2;
            }
            if (t2[i]==1 and t2[i+1]==1) {
                ans-=2;
            }
        } else {
            if (t[i]==1 and t2[i]==1 and i%2==0) {
                ans-=2;
            }
        }
    }

    cout << ans << endl;



    return 0;
}

