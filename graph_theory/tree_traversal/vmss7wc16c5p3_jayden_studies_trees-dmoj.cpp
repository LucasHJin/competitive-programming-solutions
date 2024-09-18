#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//tree diameter (number of nodes on the longest path between any two nodes)
    //with bfs

pair<int, int> bfs(int start, int n, vector<vector<int>> adjList) {
    vector<int> dist(n+1, -1); //distances of each node from starting node
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    //farthest for answer
    int farthest = start;
    //normal bfs implementation
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor: adjList[node]) {
            if (dist[neighbor]==-1) { //if unvisited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthest]) {
                    farthest = neighbor; 
                }
            }
        }
    }

    return {farthest, dist[farthest]}; //farthest node and distance
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adjList(n+1); //create adjacency list (connections for each node)
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //farthest node from any node (choose 1 in this case)
    pair<int, int> fir_bfs = bfs(1, n, adjList);
    //farthest node from above found node (because above finds node part of farthest path)
    pair<int, int> sec_bfs = bfs(fir_bfs.first, n, adjList);

    cout << sec_bfs.second << endl;

    return 0;
}