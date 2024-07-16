#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;


//grid -> define movements (coord offsets)
    //no adjacency list


//const means can't edit it
bool isValid(const vector<vector<bool>>& vis, const vector<vector<int>>& grid, int curr_row, int curr_col, int total_row, int total_col) {
    //if out of bounds
    if (curr_row<0 or curr_col<0 or curr_row>=total_row or curr_col>=total_col)
        return false;
 
    //if cell is already visited
    if (vis[curr_row][curr_col])
        return false;

    if (grid[curr_row][curr_col] == 0) 
        return false;
 
    //otherwise valid
    return true;
}

//for x
int diff_Row[] = {-1, 0, 1, 0};
//for y
int diff_Col[] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    //grid (# of rows X # of columns) (n x m)
    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<int, int>> togo;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> time(n, vector<int>(m, INT_MAX));

    //input characters
    char c;
    //end cell
    pair<int, int> end_cell;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> c;
            if (c=='s') {
                //start
                togo.push({i, j});
                visited[i][j] = true;
                time[i][j] = -1;
                grid[i][j] = 1;
            } else if (c=='e') {
                //end
                end_cell = {i, j};
                grid[i][j] = 1;
            } else if (c=='.') {
                //traversable
                grid[i][j] = 1;
            } else {
                //non traversable
                grid[i][j] = 0;
            }
        }
    }

    bool possible = false;

    while (!togo.empty()) {
        //getting current cell
        pair<int, int> curr_cell = togo.front();
        int x = curr_cell.first;
        int y = curr_cell.second;

        if (curr_cell == end_cell) {
            possible = true;
            break;
        }

        //removing front of q (already addressed)
        togo.pop();

        //going through each of the 4 possible paths to adjacent (up, down, left, right)
        for (int i=0; i<4; i++) {
            int adj_x = x + diff_Row[i];
            int adj_y = y + diff_Col[i];

            //if it is a valid movement, move to it
            if (isValid(visited, grid, adj_x, adj_y, n, m)) {
                togo.push({adj_x, adj_y});
                visited[adj_x][adj_y] = true;
                time[adj_x][adj_y] = time[x][y] + 1;
            }

        }
    }

    /*
    time is just wonky in this question -> need to start at -1 because doesn't count moving onto end as a minute

    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << time[i][j] << " ";
        }
        cout << endl;
    }
    */


    if (possible) {
        cout << time[end_cell.first][end_cell.second] << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}

