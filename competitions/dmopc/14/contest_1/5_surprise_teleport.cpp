#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int r, c;

bool isValid(const vector<vector<bool>>& vis, const vector<vector<char>>& grid, int curr_row, int curr_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=r or curr_col>=c)
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
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    queue<pair<int, int>> togo;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<vector<int>> distance(r, vector<int>(c, INT_MAX));

    //start
    int y, x;
    cin >> y >> x;
    visited[y][x] = true;
    togo.push({y, x});
    distance[y][x] = 0;

    //end
    cin >> y >> x;
    pair<int, int> end = {y, x};

    //input
    string row;
    for (int i=0; i<r; i++) {
        cin >> row;
        char cell;
        for (int j=0; j<c; j++) {
            cell = row[j];
            grid[i][j] = cell;
        }
    }

    //bfs
    while (!togo.empty()) {
        pair<int, int> curr_cell = togo.front();
        //curr row
        int y = curr_cell.first;
        //curr col
        int x = curr_cell.second;

        togo.pop();

        for (int i=0; i<4; i++) {
            //new row
            int adj_y = y + diff_Row[i];
            //new col
            int adj_x = x + diff_Col[i];

            if (isValid(visited, grid, adj_y, adj_x)) {
                togo.push({adj_y, adj_x});
                visited[adj_y][adj_x] = true;
                distance[adj_y][adj_x] = distance[y][x] + 1;
            }

        }

    }

    /*
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    //answer
    int t;
    cin >> t;
    int cy, cx;
    int max_time = 0;

    for (int i=0; i<t; i++) {
        cin >> cy >> cx;
        if (distance[cy][cx] != INT_MAX) {
            max_time = max(max_time, distance[end.first][end.second] - distance[cy][cx]);
        }
    }

    cout << max_time << endl;



    return 0;
}

