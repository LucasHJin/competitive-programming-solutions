#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int n, h;


bool isValid(const vector<vector<bool>>& vis, const vector<vector<int>>& grid, int curr_row, int curr_col, int prev_row, int prev_col) {
    //if out of bounds
    if (curr_row<0 or curr_col<0 or curr_row>=n or curr_col>=n)
        return false;
 
    //if cell is already visited
    if (vis[curr_row][curr_col])
        return false;

    //height diff is at most h
    if (abs(grid[curr_row][curr_col]-grid[prev_row][prev_col]) > h) {
        return false;
    }
 
    //otherwise valid
    return true;
}

//for x
int diff_Row[] = {-1, 0, 1, 0};
//for y
int diff_Col[] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;

    vector<vector<int>> grid(n, vector<int>(n));
    queue<pair<int, int>> togo;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    pair<int, int> end_cell = {n-1, n-1};

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    //starting node
    togo.push({0, 0});
    visited[0][0] = true;
    bool possible = false;


    while (!togo.empty()) {
        pair<int, int> curr_cell = togo.front();
        int x = curr_cell.first;
        int y = curr_cell.second;

        if (curr_cell == end_cell) {
            possible = true;
            break;
        }

        togo.pop();

        //going through each of the 4 possible paths to adjacent (up, down, left, right)
        for (int i=0; i<4; i++) {
            int adj_x = x + diff_Row[i];
            int adj_y = y + diff_Col[i];

            if (isValid(visited, grid, adj_x, adj_y, x, y)) {
                togo.push({adj_x, adj_y});
                visited[adj_x][adj_y] = true;
            }

        }
    }

    if (possible) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }


    return 0;
}

