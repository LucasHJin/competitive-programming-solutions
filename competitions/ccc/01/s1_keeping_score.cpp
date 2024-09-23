#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    vector<char> suits = {'C', 'D', 'H', 'S'};
    unordered_map<char, string> suitsMap;
    suitsMap['C'] = "Clubs";
    suitsMap['D'] = "Diamonds";
    suitsMap['H'] = "Hearts";
    suitsMap['S'] = "Spades";

    string cards;
    cin >> cards;
    int count = 0;
    int points = 0;
    int total_count = 0;
    bool first = true;
    int prev_points = 0;

    cout << "Cards Dealt  Points";

    for (auto val: cards) {
        if (find(suits.begin(), suits.end(), val) != suits.end() or total_count==16) {
            if (!first) {
                if (count==0) {
                    points += 3;
                } else if (count==1) {
                    points += 2;
                } else if (count==2) {
                    points += 1;
                }
                count = 0;
                cout << points-prev_points;
                prev_points = points;
            }
            cout << endl;
            cout << suitsMap[val] << " ";
            first = false;
        } else {
            count += 1;
            if (val=='A') {
                points += 4;
            } else if (val=='K') {
                points += 3;
            } else if (val=='Q') {
                points += 2;
            } else if (val=='J') {
                points += 1;
            }
            cout << val << " ";
        }
    }

    if (count==0) {
        points += 3;
    } else if (count==1) {
        points += 2;
    } else if (count==2) {
        points += 1;
    }

    cout << points-prev_points << endl;
    cout << " Total   " << points << endl;



    return 0;
}

