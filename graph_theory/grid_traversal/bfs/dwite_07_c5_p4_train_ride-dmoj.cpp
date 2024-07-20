#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int diff_Row[] = {0, 1, 0, -1, 1, 1, -1, -1};
int diff_Col[] = {1, 0, -1, 0, -1, 1, -1, 1};

bool isValid(const vector<vector<char>>& grid, const vector<vector<bool>>& visited, int row, int col, int height) {
    if (row<0 or col<0 or row>=height or col>=10) {
        return false;
    }
    
    if (visited[row][col]) {
        return false;
    }

    if (grid[row][col] == ' ') {
        return false;
    }

    return true;

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<5; i++) {
        string line;
        vector<string> lines;

        while (getline(std::cin, line)) {
            if (line == "xxxxxxxxxx") {
                break;
            }
            lines.push_back(line);
        }

        vector<vector<char>> grid(lines.size(), vector<char>(10));
        vector<vector<bool>> visited(lines.size(), vector<bool>(10));
        queue<pair<int, int>> togo;
        vector<vector<int>> distance(lines.size(), vector<int>(10));

        pair<int, int> end;
        for (int j=0; j<lines.size(); j++) {
            for (int k=0; k<10; k++) {
                char cell = lines[j][k];
                if (cell == 'S') {
                    grid[j][k] = cell;
                    visited[j][k] = true;
                    distance[j][k] = 0;
                    togo.push({j, k}); //y, x
                } else if (cell == 'E') {
                    grid[j][k] = cell;
                    end = {j, k};
                } else {
                    grid[j][k] = cell;
                }
            }
        }


        while (!togo.empty()) {
            pair<int, int> cell = togo.front();
            int y = cell.first;
            int x = cell.second;

            if (cell == end) {
                cout << distance[y][x] << endl;
                break;
            }

            togo.pop();

            for (int j=0; j<8; j++) {
                int adjy = y + diff_Col[j];
                int adjx = x + diff_Row[j];

                if (isValid(grid, visited, adjy, adjx, lines.size())) {
                    visited[adjy][adjx] = true;
                    distance[adjy][adjx] = distance[y][x] + 1;
                    togo.push({adjy, adjx});
                }

            }

        }
        


    }

    return 0;
    
}

