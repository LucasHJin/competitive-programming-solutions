#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
 
using namespace std;

struct player {
    int c;
    char team;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<player>> graph(n);
    vector<vector<char>> graph2(n, vector<char>(m, '.'));
    for (int i=0; i<n; i++) {
        string row;
        cin >> row;
        for (int j=0; j<m; j++) {
            if (row[j]!='.') {
                graph[i].push_back({j, row[j]});
                graph2[i][j] = 'Y';
            }
        }
    }

    for (int r=0; r<n; r++) {
        vector<int> teamA, teamB;
        for (auto player: graph[r]) {
            if (player.team=='A') {
                teamA.push_back(player.c);
            } else {
                teamB.push_back(player.c);
            }
        }

        for (int col: teamA) {
            auto it = lower_bound(teamB.begin(), teamB.end(), col+1);
            //closest possible blocker
            if (it!=teamB.end() and *it<=col+k) {
                graph2[r][col] = 'N';
            }
        }

        for (int col: teamB) {
            auto it = lower_bound(teamA.begin(), teamA.end(), col-k);
            //closest possible blocker
            if (it!=teamA.end() and *it>=col-k and *it<col) {
                graph2[r][col] = 'N';
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << graph2[i][j];
        } cout << "\n";
    }
    

    
    return 0;
}