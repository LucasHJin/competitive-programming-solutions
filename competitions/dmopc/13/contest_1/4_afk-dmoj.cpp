#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int t, l, w;

bool isValid(const vector<vector<bool>>& vis, const vector<vector<char>>& grid, int curr_row, int curr_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=w or curr_col>=l)
        return false;
 
    if (vis[curr_row][curr_col])
        return false;

    if (grid[curr_row][curr_col] == 'X') {
        return false;
    }
 
    return true;
}

int diff_Row[] = {-1, 0, 1, 0};
int diff_Col[] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> l >> w;
        vector<vector<char>> grid(w, vector<char>(l));
        queue<pair<int, int>> togo;
        vector<vector<bool>> visited(w, vector<bool>(l, false));
        vector<vector<int>> distance(w, vector<int>(l, INT_MAX));

        string row;
        pair<int, int> end;
        for (int i=0; i<w; i++) {
            cin >> row;
            char cell;
            for (int j=0; j<l; j++) {
                cell = row[j];
                if (cell == 'C') {
                    grid[i][j] = 'C';
                    togo.push({i, j});
                    visited[i][j] = true;
                    distance[i][j] = 0;
                } else if (cell == 'W') {
                    grid[i][j] = 'W';
                    end = {i, j};
                } else {
                    grid[i][j] = cell;
                }
            }
        }

        while (!togo.empty()) {
            pair<int, int> curr_cell = togo.front();
            int x = curr_cell.first;
            int y = curr_cell.second;

            togo.pop();

            for (int i=0; i<4; i++) {
                int adj_x = x + diff_Row[i];
                int adj_y = y + diff_Col[i];

                if (isValid(visited, grid, adj_x, adj_y)) {
                    togo.push({adj_x, adj_y});
                    visited[adj_x][adj_y] = true;
                    distance[adj_x][adj_y] = distance[x][y] + 1;
                }

            }
        }

        //output outside just in case never possible to reach
        if (distance[end.first][end.second] < 60) {
            cout << distance[end.first][end.second] << endl;
        } else {
            cout << "#notworth" << endl;
        }

    }


    return 0;
}

