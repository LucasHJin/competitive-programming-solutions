#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int move;
    cin >> move;
    int pos = 1;
    vector<int> shift = {9, 40, 67, 54, 90, 99};
    unordered_map<int, int> shiftM;
    shiftM[9]=34;
    shiftM[40]=64;
    shiftM[67]=86;
    shiftM[54]=19;
    shiftM[90]=48;
    shiftM[99]=77;

    bool won = false;
    while (move!=0) {
        //ladders
            //9->34
            //40->64
            //67->86
        //snakes
            //54->19
            //90->48
            //99->77
        if (pos+move<=100) {
            pos += move;
        }
        if (find(shift.begin(), shift.end(), pos) != shift.end()) {
            pos = shiftM[pos];
        }

        if (pos==100) {
            won = true;
            cout << "You are now on square " << pos << endl;
            break;
        }
        cout << "You are now on square " << pos << endl;

        cin >> move;
    }
    if (won) {
        cout << "You Win!" << endl;
    } else {
        cout << "You Quit!" << endl;
    }


    return 0;
}

