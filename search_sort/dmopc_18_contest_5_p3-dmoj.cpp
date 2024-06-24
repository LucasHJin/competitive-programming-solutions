#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;

//method 1
/*
int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> c(n);

    for (int i=0; i<n; i++) {
        cin >> c[i];
    }

    ll max_l = 0;
    int i = 0;
    ll sum = 0;
    
    for (int j=0; j<n; j++) {
        sum += c[j];
        while (sum >= m and i<=j) {
            sum -= c[i];
            i += 1;
        }

        if (max_l < j-i+1) {
            max_l = j-i+1;
        }
    }   

    cout << max_l << endl;



    return 0;
}
*/

//method 2
int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    ll max_l = 0;
    int i = 0, j = 0;
    ll sum = 0;

    while (j < n) {
        sum += c[j];
        //reduce until you have next valid answer (if needed)
        // i<=j because i!>j (supposed to be left pointer)
        while (sum >= m and i <= j) {
            sum -= c[i];
            i++;
        }

        if (max_l < j-i+1) {
            max_l = j-i+1;
        }

        j++;
    }

    cout << max_l << endl;

    return 0;
}