#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> des;
    vector<int> aps;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        des.push_back(temp);
    }
    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        aps.push_back(temp);
    }
    
    int count = 0;
    int i = 0, j = 0;

    sort(des.begin(), des.end());
    sort(aps.begin(), aps.end());

    //two pointer technique -> replace O(n^2)
    while (i<n and j<m) {
        if (des[i]-k>aps[j]) { //aps value too small -> need to go to next one
            j++;
        } else if (des[i]+k<aps[j]) { //des value too small -> need to go to next one
            i++;
        } else { //aps value in range of des value +- k -> move onto next set of ap and des and increase count
            count++;
            i++;
            j++;
        }
    }

    cout << count << endl;

    
    return 0;
}