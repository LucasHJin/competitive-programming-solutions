#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

bool isValid(const vector<vector<bool>>& vis, const vector<vector<char>>& grid, int curr_row, int curr_col) {
    //if out of bounds
    if (curr_row<0 or curr_col<0 or curr_row>=10 or curr_col>=10)
        return false;
 
    //if cell is already visited
    if (vis[curr_row][curr_col])
        return false;

    //height diff is at most h
    if (grid[curr_row][curr_col] == '#') {
        return false;
    }
 
    //otherwise valid
    return true;
}

//for x
int diff_Row[] = {-1, 0, 1, 0, -1, -1, 1, 1};
//for y
int diff_Col[] = {0, 1, 0, -1, -1, 1, -1, 1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    for (int x=0; x<5; x++) {
        vector<vector<char>> grid(10, vector<char>(10));
        queue<pair<int, int>> togo;
        vector<vector<bool>> visited(10, vector<bool>(10, false));
        vector<vector<int>> distance(10, vector<int>(10, INT_MAX));

        char c;
        pair<int, int> start = {INT_MAX, INT_MAX};
        pair<int, int> temp = {INT_MAX, INT_MAX};
        pair<int, int> end;


        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                cin >> c;
                if (c=='.') {
                    grid[i][j] = c;
                } else if (c=='#') {
                    grid[i][j] = c;
                } else {
                    if (start == temp){
                        start.first = i;
                        start.second = j;
                        visited[i][j] = true;
                        distance[i][j] = 0;
                        togo.push(start);
                        grid[i][j] = 'X';
                    } else {
                        end.first = i;
                        end.second = j;
                        grid[i][j] = 'X';
                    }
                }
            }
        }
        
        //get rid of lines (filler input)
        char fill;
        for (int i=0; i<10; i++) {
            cin >> fill;
        }


        while (!togo.empty()) {
            pair<int, int> curr_cell = togo.front();
            int x = curr_cell.first;
            int y = curr_cell.second;

            if (curr_cell == end) {
                cout << distance[x][y] << endl;
                break;
            }

            togo.pop();

            for (int i=0; i<8; i++) {
                int adj_x = x + diff_Row[i];
                int adj_y = y + diff_Col[i];

                if (isValid(visited, grid, adj_x, adj_y)) {
                    togo.push({adj_x, adj_y});
                    visited[adj_x][adj_y] = true;
                    distance[adj_x][adj_y] = distance[x][y] + 1;
                }

            }
        }
    }


    return 0;
}

