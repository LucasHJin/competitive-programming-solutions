#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    //use a pair to not have to iterate through a vector again to find actual index value in original array
    vector<pair<int, int>> a(n);

    //input values + original index
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    //sort values
    sort(a.begin(), a.end());

    int ai = -1;
    int aj = -1;
    int ak = -1;

    //need loop for third pointer (try each one once in relation to the other 2)
    for (int i=0; i<n; i++) {
        int j = i+1;
        int k = n-1;
        int sum = 0;
        bool found = false;
        while (j<k) {
            sum = a[i].first + a[j].first + a[k].first;
            if (sum == x) {
                ai = a[i].second;
                aj = a[j].second;
                ak = a[k].second;
                found = true;
                break;
            } else if (sum<x) {
                j++;
            } else {
                k--;
            }
        }
        if (found) {
            break;
        }
    }

    if (ai!=-1 and aj!=-1 and ak!=-1) {
        vector<int> temp;
        temp.push_back(ai+1);
        temp.push_back(aj+1);
        temp.push_back(ak+1);
        sort(temp.begin(), temp.end());

        cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}