#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n+1);

    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    int a, b;
    cin >> a >> b;

    unordered_set<int> visited;
    queue<int> togo;
    vector<int> path_len(n+1, INT_MAX);

    visited.emplace(a);
    togo.push(a);
    path_len[a] = 0;

    vector<int> vals;

    while (!togo.empty()) {
        int curr_node = togo.front();

        if (curr_node == b) {
            cout << m-path_len[b] << endl;
            //found
            break;
        }
        togo.pop();

        vals = adjList[curr_node];
        for (auto next: vals) {
            if (visited.find(next) == visited.end()) {
                togo.push(next);
                visited.emplace(next);
                path_len[next] = path_len[curr_node] + 1;
            }
        }
    }


    
    return 0;
}

