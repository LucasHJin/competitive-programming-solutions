#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    cin.ignore();

    unordered_map<int, int> balls;
    int unique = 0;

    //1 remove, 2 put in, 3 amount of #
    string query;
    for (int i=0; i<q; i++) {
        getline(cin, query);
        int x;
        int command;
        stringstream ss(query);
        ss >> command;

        //cout << query << endl;

        if (query.size() == 1) {
            //3
            cout << unique << endl;
        } else if (query[0] == '1') {
            //1
            ss >> x;
            if (balls[x] == 0) {
                unique++;
            }
            balls[x]++;
        } else {
            //2
            ss >> x;
            if (balls[x] > 0) {
                balls[x]--;
                if (balls[x] == 0) {
                    unique--;
                }
            }
        }
    }
    


    return 0;
}

