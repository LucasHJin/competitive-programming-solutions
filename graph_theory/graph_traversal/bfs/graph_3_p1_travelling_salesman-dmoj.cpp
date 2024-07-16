#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//multisource bfs -> starts at multiple sources simultaneously
    //explore all nodes in parallel
    //useful -> shortest path from multile nodes to all other nodes/connectivity between nodes

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
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    unordered_set<int> visited;
    queue<int> togo;
    vector<int> time(n+1, INT_MAX);

    //adding all starting points to queue and visited 
    int k;
    int start;
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> start;
        visited.emplace(start);
        togo.push(start);
        time[start] = 0;
    }

    //just normal bfs now
        //because its queued in the order where if starting = a, b, c -> this order is always preserved
        //nodes a then b then c then childs of a, childs of b, childs of c...
    while (!togo.empty()) {

        int curr_node = togo.front();

        togo.pop();

        for (auto next: adjList[curr_node]) {
            if (visited.find(next) == visited.end()) {
                visited.emplace(next);
                togo.push(next);
                time[next] = time[curr_node] + 1;
            }
        }
    }

    //biggest val = total time taken
    int max_time = 0;
    for (int i=1; i<=n; i++) {
        max_time = max(max_time, time[i]);
    }

    cout << max_time << endl;


    return 0;
}

