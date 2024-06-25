#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;


int main() {
    //inputs
    int n, t;
    cin >> n;
    vector<int> cows(n);
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    cin >> t;

    for (int i=0; i<t; i++) {
        int test_value;
        cin >> test_value;
        //2pointer

        int j = 0;
        int k = 0;
        ll sum = 0;
        int total = 0;

        while (k<n) {
            sum += cows[k];
            if (sum==test_value) {
                total += 1;
            }
            while (sum>=test_value) {
                sum-=cows[j];
                j++;
                if (sum==test_value) {
                    total += 1;
                }
            }

            k++;
        }

        cout << total << " ";

    }




    return 0;
}
