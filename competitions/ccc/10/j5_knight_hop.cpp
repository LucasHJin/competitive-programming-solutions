#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//grid bfs

int diff_Row[] = {1, -1, 2, -2, 2, -2, 1, -1};
int diff_Col[] = {-2, -2, -1, -1, 1, 1, 2, 2};

bool isValid(const vector<vector<bool>>& visited, int row, int col) {
    if (row<0 or col<0 or row>=8 or col>=8) {
        return false;
    }
    
    if (visited[row][col]) {
        return false;
    }

    return true;

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //8x8
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<pair<int, int>> togo;
    vector<vector<int>> distance(8, vector<int>(8, INT_MAX));

    pair<int, int> start;
    pair<int, int> end;

    cin >> start.first >> start.second;
    cin >> end.first >> end.second;

    start.first -= 1;
    start.second -= 1;
    end.first -= 1;
    end.second -= 1;


    visited[start.second][start.first] = true;
    togo.push({start.second, start.first});
    distance[start.second][start.first] = 0;

    while (!togo.empty()) {
        int y = togo.front().first;
        int x = togo.front().second;

        if (y==end.second and x==end.first) {
            cout << distance[y][x] << endl;
            break;
        }

        togo.pop();

        for (int i=0; i<8; i++) {
            int adjy = y + diff_Row[i];
            int adjx = x + diff_Col[i];

            if (isValid(visited, adjy, adjx)) {
                visited[adjy][adjx] = true;
                togo.push({adjy, adjx});
                distance[adjy][adjx] = distance[y][x] + 1;
            }
        }

    }



    return 0;
}

