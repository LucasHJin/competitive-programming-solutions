#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


void gen(int n, int k, const vector<int>& r, vector<int> curr, int ind) {
    //base case
    if (ind == n) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += curr[i];
        }
        //checking if sum divisible by k
        if (sum%k == 0) {
            //printing answer
            for (int i=0; i<n; i++) {
                cout << curr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    
    //go through all values for each r index (1<=v<=R_i)
        //do this for each value
    for (int value=1; value<=r[ind]; value++) {
        curr[ind] = value;
        gen(n, k, r, curr, ind+1);
    }
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //between 1 and R_i, multiple of k
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for (int i=0; i<n; i++) {
        cin >> r[i];
    }

    vector<int> curr(n);

    gen(n, k, r, curr, 0);

}

