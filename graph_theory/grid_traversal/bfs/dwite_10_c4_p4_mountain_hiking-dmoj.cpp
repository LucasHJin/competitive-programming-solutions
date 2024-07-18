#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs + MULTISOURCE

bool isValid(const vector<vector<bool>>& vis, const vector<vector<int>>& grid, int curr_row, int curr_col, int prev_row, int prev_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=10 or curr_col>=10)
        return false;
 
    if (vis[curr_row][curr_col])
        return false;

    if (abs(grid[curr_row][curr_col]-grid[prev_row][prev_col]) > 1) {
        return false;
    }
 
    return true;
}

//for x
int diff_Row[] = {-1, 0, 1, 0};
//for y
int diff_Col[] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    for (int x=0; x<5; x++) {
        vector<vector<int>> grid(10, vector<int>(10));
        queue<pair<int, int>> togo;
        vector<vector<bool>> visited(10, vector<bool>(10, false));
        vector<vector<int>> distance(10, vector<int>(10, INT_MAX));

        for (int i=0; i<10; i++) {
            //need this because no spaces
            string row;
            cin >> row;
            for (int j=0; j<10; j++) {
                grid[i][j] = row[j] - '0';
            }
        }

        //filler input
        string temp;
        cin >> temp;

        //starting points -> don't need to worry about overwriting other starting because visited true
        for (int i=0; i<10; i++) {
            visited[i][0] = true;
            distance[i][0] = 0;
            togo.push({i, 0});
        }

        //will give lowest because it goes column by column
        while (!togo.empty()) {
            pair<int, int> curr_cell = togo.front();
            int x = curr_cell.first;
            int y = curr_cell.second;

            togo.pop();

            for (int i=0; i<4; i++) {
                int adj_x = x + diff_Row[i];
                int adj_y = y + diff_Col[i];

                if (isValid(visited, grid, adj_x, adj_y, x, y)) {
                    togo.push({adj_x, adj_y});
                    visited[adj_x][adj_y] = true;
                    distance[adj_x][adj_y] = distance[x][y] + 1;
                }

            }
        }

        bool possible = false;
        int min_dis = INT_MAX;

        for (int i=0; i<10; i++) {
            if (distance[i][9]!=INT_MAX) {
                possible = true;
                min_dis = min(min_dis, distance[i][9]);
            }
        }

        if (possible) {
            cout << min_dis << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }


    }


    return 0;
}

