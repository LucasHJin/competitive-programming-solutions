#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//dfs based tp sort
    //attempt
    
void dfs(int r, int c, vector<vector<vector<pair<int, int>>>> &adjList, vector<vector<bool>> &visited, vector<pair<int, int>> &result) {
    visited[r][c] = true;

    for (auto adj_node : adjList[r][c]) {
        if (!visited[adj_node.first][adj_node.second]) {
            dfs(adj_node.first, adj_node.second, adjList, visited, result);
        }
    }

    result.push_back({r, c}); //push after visiting all adjacent nodes
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<vector<pair<int, int>>>> adjList(n, vector<vector<pair<int, int>>>(m));
    vector<pair<pair<int, int>, char>> cars;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> result;
    vector<pair<int, int>> carN;
    vector<pair<int, int>> carS;
    vector<pair<int, int>> carE;
    vector<pair<int, int>> carW;

    for (int i=0; i<n; i++) {
        string line;
        cin >> line;
        for (int j=0; j<m; j++) {
            char cell = line[j];
            if (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E') {
                cars.emplace_back(make_pair(i, j), cell);
                if (cell=='N') {
                    carN.emplace_back(i, j);
                }
            }
        }
    }

    for (auto car: cars) {
        int r = car.first.first;
        int c = car.first.second;
        char dir = car.second;

        if (dir == 'N') {
            for (auto car2: cars) {
                if (car2.first.first < r && car2.first.second == c) {
                    adjList[car2.first.first][c].push_back({r, c});
                }
            }
        } else if (dir == 'S') {
            for (auto car2: cars) {
                if (car2.first.first > r && car2.first.second == c) {
                    adjList[car2.first.first][c].push_back({r, c});
                }
            }
        } else if (dir == 'E') {
            for (auto car2: cars) {
                if (car2.first.second > c && car2.first.first == r) {
                    adjList[r][car2.first.second].push_back({r, c});
                }
            }
        } else if (dir == 'W') {
            for (auto car2: cars) {
                if (car2.first.second < c && car2.first.first == r) {
                    adjList[r][car2.first.second].push_back({r, c});
                }
            }
        }
    }

    for (auto car: cars) {
        int r = car.first.first;
        int c = car.first.second;
        if (!visited[r][c]) {
            dfs(r, c, adjList, visited, result);
        }
    }

    reverse(result.begin(), result.end()); //reverse since dfs gives reversed

    for (auto it : result) {
        cout << "(" << it.first << "," << it.second << ")" << endl;
    }

    return 0;
}