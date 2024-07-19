#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int h, l;

bool isValid(const vector<vector<bool>>& vis, const vector<vector<char>>& grid, int curr_row, int curr_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=h or curr_col>=l)
        return false;
 
    if (vis[curr_row][curr_col])
        return false;

    if (grid[curr_row][curr_col] == '#') {
        return false;
    }
 
    return true;
}

int diff_Row[] = {-1, 0, 1, 0};
int diff_Col[] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<5; i++) {
        cin >> h >> l;
        vector<vector<char>> grid(h, vector<char>(l));
        queue<pair<int, int>> togo;
        vector<vector<bool>> visited(h, vector<bool>(l, false));
        vector<vector<int>> distance(h, vector<int>(l, INT_MAX));
        int sum = 0;

        string row;
        pair<int, int> a;
        pair<int, int> b;
        pair<int, int> c;
        for (int i=0; i<h; i++) {
            cin >> row;
            char cell;
            for (int j=0; j<l; j++) {
                cell = row[j];
                if (cell == 'A') {
                    grid[i][j] = 'A';
                    a = {i, j};
                } else if (cell == 'B') {
                    grid[i][j] = 'B';
                    b = {i, j};
                } else if (cell == 'C') {
                    grid[i][j] = 'C';
                    c = {i, j};
                } else {
                    grid[i][j] = cell;
                }
            }
        }

        vector<pair<int, int>> points;
        points.push_back(a);
        points.push_back(b);
        points.push_back(c);
        points.push_back(a);


        for (int i=0; i<3; i++) {
            togo.push(points[i]);
            visited[points[i].first][points[i].second] = true;
            distance[points[i].first][points[i].second] = 0;

            while (!togo.empty()) {
                pair<int, int> curr_cell = togo.front();
                int x = curr_cell.first;
                int y = curr_cell.second;

                if (curr_cell == points[i+1]) {
                    sum += distance[points[i+1].first][points[i+1].second];
                    break;
                }

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

            while (!togo.empty()) {
                togo.pop();
            }

            for (int j=0; j<h; j++) {
                for (int k=0; k<l; k++) {
                    distance[j][k] = INT_MAX;
                    visited[j][k] = false;
                }
            }


        }

        cout << sum << endl;

    }


    return 0;
}

