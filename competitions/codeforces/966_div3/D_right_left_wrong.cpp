#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int x=0; x<t; x++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        vector<long long> preSum(n+1,0);
        for (int i=1; i<=n; i++) {
            preSum[i] = preSum[i - 1] + a[i - 1];
        }

        ll maxScore = 0;

        int l=0; 
        int r=n-1;

        while (l<r) {
            if (s[l]=='L' and s[r]=='R') {
                ll sum = preSum[r+1]-preSum[l];
                maxScore += sum;
                l+=1;
                r-=1;
            } else if (s[l]!='L') {
                l+=1;
            } else if (s[r]!='R') {
                r-=1;
            }
        }

        cout << maxScore << endl;

    }
}

