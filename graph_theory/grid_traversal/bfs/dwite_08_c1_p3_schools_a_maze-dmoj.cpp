#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int diff_Row[] = {-1, 0, 1, 0};
int diff_Col[] = {0, 1, 0, -1};


bool isValid(const vector<vector<bool>>& vis, const vector<vector<char>>& grid, int curr_row, int curr_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=10 or curr_col>=19)
        return false;
 
    if (vis[curr_row][curr_col])
        return false;

    if (grid[curr_row][curr_col] == '#') {
        return false;
    }
 
    return true;
}

//no & because want to edit copy
void bfs(const vector<vector<char>> grid, vector<pair<int, int>> points, vector<vector<int>>& dist_mat, int idx) {
    vector<vector<bool>> visited(10, vector<bool>(19, false));
    vector<vector<int>> distance(10, vector<int>(19, INT_MAX));
    queue<pair<int, int>> togo;

    togo.push(points[idx]);
    visited[points[idx].first][points[idx].second] = true;
    distance[points[idx].first][points[idx].second] = 0;

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

    //put into distance matrix
    for (int i=0; i<12; i++) {
        if (i!=idx) {
            dist_mat[idx][i] = distance[points[i].first][points[i].second];
            dist_mat[i][idx] = distance[points[i].first][points[i].second];
        } else {
            dist_mat[idx][idx] = 0;
        }
    }

}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    //row # x col #
    vector<vector<char>> grid(10, vector<char>(19));
    vector<pair<int, int>> points(12);
    vector<vector<int>> distance_matrix(12, vector<int>(12, 0));
    int sum;

    //getting position of all points
    string row;
    for (int i=0; i<10; i++) {
        cin >> row;
        char cell;
        for (int j=0; j<19; j++) {
            cell = row[j];
            if (cell=='.' or cell=='#') {
                grid[i][j] = cell;
            } else {
                grid[i][j] = cell;
                int ind = cell-'A';
                points[ind] = {i, j};
            }
        }
    }
    
    //calc the distances between each point and every other point
    for (int i=0; i<12; i++) {
        bfs(grid, points, distance_matrix, i);
    }
    
    //take in inputs and give answers
    string inp;
    for (int i=0; i<5; i++) {
        sum = 0;
        cin >> inp;
        for (int j=0; j<inp.length()-1; j++) {
            sum += distance_matrix[inp[j]-'A'][inp[j+1]-'A'];
        }
        cout << sum << endl;
    }



    return 0;
}

