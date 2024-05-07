#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

//greedy
 
int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }
   
    sort(coins.begin(), coins.end());
   
    //1 so it is 1 above each time
    ll max = 1;
   
    for (int i=0; i<n; i++) {
        if (coins[i]>max) {
            break;
        } else {
            //want to add to 1 above because for it to fail adding up to it, the minimum is 1 between current max and next number
            //i.e. if you have 5 current sum and next number is 7, there is space 6 which can't be filled up
            max = max + coins[i];
        }
    }
   
    cout << max << endl;
   
   
   
    return 0;
} 