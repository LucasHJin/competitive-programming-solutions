#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, b, q;
    cin >> n >> m >> b >> q;

    vector<vector<pair<int, int>>> graph(n+1);
    int x, y, z;
    for (int i=0; i<m; i++) {
        cin >> x >> y >> z;
        addEdge(graph, x, y, z);
    }

    vector<ll> time(n+1, __LONG_LONG_MAX__);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    time[b] = 0;
    pq.push({0, b});

    while (!pq.empty()) {
        int node = pq.top().second;
        ll t = pq.top().first;

        pq.pop();

        if (t>time[node]) {
            continue;
        }

        for (auto adj: graph[node]) {
            int adj_node = adj.first;
            ll adj_t = adj.second;

            if (t+adj_t < time[adj_node]) {
                time[adj_node] = t+adj_t;
                pq.push({time[adj_node], adj_node});
            }
        }

    }

    int query;
    for (int i=0; i<q; i++) {
        cin >> query;
        if (time[query] != __LONG_LONG_MAX__) {
            cout << time[query] << endl;
        } else {
            cout << -1 << endl;
        }
    }


    return 0;
}

