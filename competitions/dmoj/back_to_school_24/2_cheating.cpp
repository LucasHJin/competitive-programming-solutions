#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;

void update(int l, int r, int v, vector<ll>& diff) {
    diff[l] += v; //fxn to update diff array (sum certain portion)
    diff[r+1] -= v; 
} 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1); //point
    vector<int> b(n+1); //num of solve
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }

    vector<ll> diff(m+2, 0); //diff array

    int curr = 1; //starting position for updating
    for (int i=1; i<=n; i++) {  
        //apply updates to the score
        if (curr+b[i]-1 <= m) {
            update(curr, curr+b[i]-1, a[i], diff);
            if (curr+b[i]-1 == m) {
                curr = 1;
            }
            else {
                curr += b[i];
            }
            //just go to value after last updated because will guarenteed be smaller (a1<a2<a3...)
        }
        else {
            //all updated even with wraps

            //update from curr to end
            update(curr, m, a[i], diff);
            b[i] -= (m-curr+1); //how many left
            //update remaining
            update(1, b[i], a[i], diff); 
            curr = b[i]+1; //set new curr
        }
    }

    //prefix sum calc for answer
    for (int i=1; i<=m; i++) {
        diff[i] += diff[i-1];
        cout << diff[i] << " ";
    }

    return 0;
}