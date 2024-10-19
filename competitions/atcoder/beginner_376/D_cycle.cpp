#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//bfs + cycle checking

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    vector<int> dist(n + 1, INT_MAX); //distance from v1
    queue<int> q;
    int minCycle = INT_MAX;

    dist[1] = 0; 
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();

        for (int v : adjList[u]) {
            //if not visited
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1; 
                q.push(v);
            } else if (v == 1) { //if start node revisit
                minCycle = min(minCycle, dist[u] + 1);
            }
        }
    }

    if (minCycle == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << minCycle << endl;
    }

    return 0;
}
