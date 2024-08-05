#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    int a, b, t;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> t;
        addEdge(graph, a, b, t);
    }

    vector<int> dist1(n, INT_MAX);
    vector<int> dist2(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //from starting point
    dist1[0] = 0;
    //{weight, node}
    pq.push({0,0});

    while (!pq.empty()) {
        int node = pq.top().second;
        int t = pq.top().first;

        pq.pop();

        //if already found a shorter path (because this would guarentee that it is a longer path when adding onto even 0)
        if (t > dist1[node]) {
            continue;
        }

        for (auto adj: graph[node]) {
            int adj_node = adj.first;
            int adj_t = adj.second;

            if (adj_t+t < dist1[adj_node]) {
                dist1[adj_node] = adj_t + t;
                pq.push({dist1[adj_node], adj_node});
            }
        }
    }

    //from ending point (because 2 way roads)
    dist2[n-1] = 0;
    pq.push({0,n-1});
    while (!pq.empty()) {
        int node = pq.top().second;
        int t = pq.top().first;

        pq.pop();

        //if already found a shorter path (because this would guarentee that it is a longer path when adding onto even 0)
        if (t > dist2[node]) {
            continue;
        }

        for (auto adj: graph[node]) {
            int adj_node = adj.first;
            int adj_t = adj.second;

            if (adj_t+t < dist2[adj_node]) {
                dist2[adj_node] = adj_t + t;
                pq.push({dist2[adj_node], adj_node});
            }
        }
    }

    //add two and find longest distance
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans,(ll)dist1[i]+dist2[i]);
    }

    cout << ans << endl;

    return 0;
}

