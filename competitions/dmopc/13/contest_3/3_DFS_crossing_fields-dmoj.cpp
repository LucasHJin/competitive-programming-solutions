#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs
int n, h;

bool isValid(const vector<vector<bool>>& vis, const vector<vector<int>>& grid, int curr_row, int curr_col, int prev_row, int prev_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=n or curr_col>=n)
        return false;
 
    if (vis[curr_row][curr_col])
        return false;

    if (abs(grid[curr_row][curr_col]-grid[prev_row][prev_col]) > h) {
        return false;
    }
 
    //otherwise valid
    return true;
}

int diff_Row[] = {-1, 0, 1, 0};
int diff_Col[] = {0, 1, 0, -1};

void dfs(vector<vector<bool>>& vis, vector<vector<int>>& grid, int row, int col) {
    //going through entire map and marking all as true or false
    vis[row][col] = true;

    int dx, dy;

    for (int i=0; i<4; i++) {
        dx = row+diff_Row[i];
        dy = col+diff_Col[i];

        if (isValid(vis, grid, dx, dy, row, col)) {
            dfs(vis, grid, dx, dy);
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    pair<int, int> end_cell = {n-1, n-1};

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(visited, grid, 0, 0);

    //if it's true, it has been visited
    bool possible = visited[n-1][n-1];

    if (possible) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }


    return 0;
}

