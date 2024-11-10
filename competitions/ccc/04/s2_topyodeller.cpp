#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> y(n, 0); //cumulative scores
    vector<int> r(n, 0); //current ranks
    vector<int> w(n, 1); //worst ranks

    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            y[j] += x;
        }

        for (int j=0; j<n; j++) {
            int t = 1; //for each yodeller, go through everybody else, and see how many are greater
            for (int p=0; p<n; p++) {
                //if not same person and greater value, update rank
                if (p != j && y[p] > y[j]) {
                    t++;
                }
            }
            //worse rank update
            if (t > w[j]) {
                w[j] = t;
            }
            //update current rank
            r[j] = t;
        }
    }

    int max_score = *max_element(y.begin(), y.end());

    for (int j=0; j<n; j++) {
        if (y[j] == max_score && r[j] == 1) { //only print those with the highest score and rank 1
            cout << "Yodeller " << (j + 1) << " is the TopYodeller: score " 
                 << y[j] << ", worst rank " << w[j] << endl;
        }
    }

    return 0;
}
