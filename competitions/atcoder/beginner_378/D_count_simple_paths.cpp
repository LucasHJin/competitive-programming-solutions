#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

// grid bfs

int h, w, k;
int diff_Row[] = {-1, 0, 1, 0};
int diff_Col[] = {0, 1, 0, -1};
int ans = 0;

bool isValid(const vector<vector<bool>>& vis, const vector<vector<char>>& grid, int curr_row, int curr_col) {
    if (curr_row < 0 || curr_col < 0 || curr_row >= h || curr_col >= w)
        return false;
    if (vis[curr_row][curr_col] || grid[curr_row][curr_col] == '#')
        return false;
    return true;
}

//dfs to explore k steps
void dfs(vector<vector<bool>>& vis, const vector<vector<char>>& grid, int row, int col, int count) {
    //mark current cell visited
    vis[row][col] = true;

    //if k moves -> increment answer and backtrack
    if (count == k) {
        ans += 1;
        vis[row][col] = false; //backtrack
        return;
    }

    //exploring all directions
    for (int i = 0; i < 4; i++) {
        int dx = row + diff_Row[i];
        int dy = col + diff_Col[i];
        if (isValid(vis, grid, dx, dy)) {
            dfs(vis, grid, dx, dy, count + 1);
        }
    }

    //backtrack (allows to be visited by other dfs starting at other points, only needed if not one specific starting point)
    vis[row][col] = false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w >> k;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i=0; i<h; i++) {
        string line;
        cin >> line;
        for (int j=0; j<w; j++) {
            char cell = line[j];
            grid[i][j] = cell;
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (grid[i][j] != '#') {
                vector<vector<bool>> visited(h, vector<bool>(w, false));
                dfs(visited, grid, i, j, 0);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
