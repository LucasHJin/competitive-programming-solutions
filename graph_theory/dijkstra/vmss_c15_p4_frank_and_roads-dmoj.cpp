#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w) {
    graph[u].push_back({v, w});
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t, n, m, g;
    cin >> t >> n >> m >> g;
    
    vector<int> query;
    int fb;
    for (int i=0; i<g; i++) {
        cin >> fb;
        query.push_back(fb);
    }

    int a, b, l;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i=0; i<m; i++) {
        cin >> a >> b >> l;
        addEdge(graph, a, b, l);
    }

    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int node = pq.top().second;
        int t = pq.top().first;

        pq.pop();

        if (t > dist[node]) {
            continue;
        }

        for (auto adj: graph[node]) {
            int adj_node = adj.first;
            int adj_t = adj.second;

            if (adj_t+t < dist[adj_node]) {
                dist[adj_node] = adj_t + t;
                pq.push({dist[adj_node], adj_node});
            }
        }
    }

    /*
    for (auto it: dist) {
        cout << it << endl;
    }
    */

    
    int count = 0;
    for (auto it: query) {
        if (dist[it]<t) {
            count += 1;
        }
    }

    cout << count << endl;
    







    return 0;
}

