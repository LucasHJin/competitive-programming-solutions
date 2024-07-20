#include <bits/stdc++.h>
#include <iostream>
#include <deque>
 
typedef long long ll;
 
using namespace std;

//grid 0-1 BFS
    //push to front if 0, push to back if 1
int n, m; 

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


bool isValid(const vector<vector<bool>>& vis, int row, int col) {
    if (row<0 or col<0 or row>=n or col>=m)
        return false;

    if (vis[row][col])
        return false;

    return true;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> cookies(n, vector<int>(m, INT_MAX));
    deque<pair<int, int>> togo;

    for (int i=0; i<n; i++) {
        string row;
        cin >> row;
        for (int j=0; j<m; j++) {
            char cell = row[j];
            grid[i][j] = row[j];
        }
    }

    if (grid[0][0] == 'C') {
        visited[0][0] = true;
        cookies[0][0] = 1;
        togo.push_back({0, 0});
    } else {
        visited[0][0] = true;
        cookies[0][0] = 0;
        togo.push_front({0, 0});
    }

    pair<int, int> end = {n-1, m-1};


    while (!togo.empty()) {
        pair<int, int> cell = togo.front();
        int y = cell.first;
        int x = cell.second;
        //cout << "______" << endl;
        //cout << y << " " << x << endl;

        if (cell == end) {
            cout << cookies[y][x] << endl;
            break;
        }

        togo.pop_front();
        
        

        for (int i=0; i<4; i++) {
            int adjy = y + dr[i];
            int adjx = x + dc[i];
            //cout << adjy << " " << adjx << " ";

            if (isValid(visited, adjy, adjx)) {
                //cout << "G ";
                if (grid[adjy][adjx] == 'C') {
                    //cout << "C";
                    visited[adjy][adjx] = true;
                    cookies[adjy][adjx] = cookies[y][x] + 1;
                    togo.push_back({adjy, adjx});
                } else {
                    //cout << "N";
                    visited[adjy][adjx] = true;
                    cookies[adjy][adjx] = cookies[y][x];
                    togo.push_front({adjy, adjx});
                }
            }
            //cout << endl;
        }
        //cout << "AA" << endl;
    }
    

    return 0;
    
}

