#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;


int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    //[n][m] (row, column)
    //vector<vector<int>> field(n, vector<int>(m, 1));
    vector<int> diffarr(n + 1, 0); //diff array for each row, n+1 for simplicity (no out of bound)

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;  
        diffarr[a]--; //decrement starting
        if (b+1 < n) {
            diffarr[b+1]++; //increment ending
        }
    }

    //difference array -> mark where it starts and ends, i.e. if 2 start at pos 0, then its -2, another starts at pos 1, its -3 from there on...

    vector<int> goods(n, m); //good for each row
    int bad = 0;
    for (int i=0; i<n; i++) {
        bad += diffarr[i];
        goods[i] += bad;
    }

    /*
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        //make all bad = 0
        for (int j = a-1; j<b; j++) {
            if (j>=0 and j<n) {
                field[j][i] = 0;
            }
        }
    }

    for (int i=0; i<n; i++) {
        int good = count(field[i].begin(), field[i].end(), 1);
        diffarr.push_back(good);
    }

    field.clear();
    field.shrink_to_fit();
    
    for (const auto& row : field) {
        for (int val: row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    for (auto it: diffarr) {
        cout << it << endl;
    }
    */

    //2 pointer
    int i = 0;
    int j = 0;
    ll sum = 0;
    ll min_l = 9223372036854775807;

    while (j<n) {
        //cout << sum << " " << goods[j] << endl;
        sum+=goods[j];
        while (sum>=k) {
            min_l = min(min_l, ll(j-i+1));
            sum-=goods[i];
            i+=1;
        }
        j+=1;
    }

    if (min_l == 9223372036854775807) {
        cout << -1 << endl;
    } else if (min_l < 0) {
        cout << 0 << endl;
    } else {
        cout << min_l << endl;
    }

    return 0;
}
