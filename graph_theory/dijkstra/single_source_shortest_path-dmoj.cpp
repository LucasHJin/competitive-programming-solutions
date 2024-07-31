#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

//adding all edges to the graph
void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1); //adjacency list
    vector<int> dist(n+1, INT_MAX);
    //creates a min heap for efficient access
    //collection of nodes, each associated with a distance value (ordered from min to max)
        //{value, node}
        //essentially represents the path
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> smallest_node;
    //not necessary, just for keeping track
    vector<bool> visited(n+1, false);


    int u, v, w;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }

    dist[1] = 0;
    smallest_node.push({0, 1});

    while (!smallest_node.empty()) {
        int curr_node = smallest_node.top().second; 
        int curr_dist = smallest_node.top().first; 

        //remove from priority queue -> extracted the node with the smallest known distance among all nodes in the queue (shortest possible distance)
            //because for any other nodes, even if they reach it, they will be > already
        smallest_node.pop();

        //if (curr_dist > dist[curr_node]) continue; -> if not using visited
        if (visited[curr_node]) {
            continue; //skip if already visited
        }

        visited[curr_node] = true; 

        for (const auto& edge : graph[curr_node]) {
            //getting the next node and weight
            int adj_node = edge.first; 
            int adj_weight = edge.second; 

            //checking if they are smaller than what is currently there (min distance)
            if (curr_dist + adj_weight < dist[adj_node]) {
                dist[adj_node] = curr_dist + adj_weight;
                smallest_node.push({dist[adj_node], adj_node});
            }
        }
    }

    //printing out min distance
    for (int i=1; i<=n; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    
    return 0;
}

