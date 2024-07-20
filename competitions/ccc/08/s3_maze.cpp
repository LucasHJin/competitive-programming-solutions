#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int t, r, c;

int diff_Row[] = {0, 1, 0, -1};
int diff_Col[] = {1, 0, -1, 0};

bool isValid(const vector<vector<char>>& grid, const vector<vector<bool>>& visited, int row, int col, int prev_row, int prev_col) {
    if (row<0 or col<0 or row>=r or col>=c) {
        return false;
    }
    
    if (visited[row][col]) {
        return false;
    }

    //check valid movement

    if (grid[row][col] == '*') {
        return false;
    }

    if (grid[prev_row][prev_col] == '|' and abs(prev_col-col) == 1) {
        return false;
    } else if (grid[prev_row][prev_col] == '-' and abs(prev_row-row) == 1) {
        return false;
    }

    return true;

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for (int a=0; a<t; a++) {
        cin >> r >> c;
        vector<vector<char>> grid(r, vector<char>(c));
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<vector<int>> distance(r, vector<int>(c, INT_MAX));
        queue<pair<int, int>> togo;

        string row;
        for (int i=0; i<r; i++) {
            cin >> row;
            for (int j=0; j<c; j++) {
                char cell = row[j];
                grid[i][j] = cell;
            }
        }

        //start = (0, 0)
        visited[0][0] = true;
        distance[0][0] = 1;
        togo.push({0, 0});
        //end = (r-1, c-1)
        pair<int, int> end = {r-1, c-1};

        bool possible = false;

        while (!togo.empty()) {
            pair<int, int> curr_cell = togo.front();
            int y = curr_cell.first;
            int x = curr_cell.second;

            if (curr_cell == end) {
                possible = true;
                break;
            }

            togo.pop();

            for (int i=0; i<4; i++) {
                int adjy = y + diff_Row[i];
                int adjx = x + diff_Col[i];
                if (isValid(grid, visited, adjy, adjx, y, x)) {
                    visited[adjy][adjx] = true;
                    distance[adjy][adjx] = distance[y][x]+1;
                    togo.push({adjy, adjx});
                }
            }
        }

        if (possible) {
            cout << distance[end.first][end.second] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
    
}

