#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<pair<int, double>>>& graph, int u, int v, double w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //1 to v
    int v, e;
    cin >> v;
    cin >> e;

    int m, n, d, s;
    double t;
    vector<vector<pair<int, double>>> graph(v+1);
    for (int i=1; i<=e; i++) {
        cin >> m >> n >> d >> s;
        t = static_cast<double>(d)/s*60;
        addEdge(graph, m, n, t);
    }

    //time, roads, node
    priority_queue<pair<pair<double, int>, int>, vector<pair<pair<double, int>, int>>, greater<pair<pair<double, int>, int>>> pq;
    //time, roads
    vector<pair<double, int>> tr(v+1, {DBL_MAX, INT_MAX});

    tr[1] = {0.0, 0};
    pq.push({{0.0, 0}, 1});

    //go based off time -> if same time then road # smallest
    while (!pq.empty()) {
        int node = pq.top().second;
        double t = pq.top().first.first;
        int r = pq.top().first.second;

        pq.pop();

        if (node == v) {
            //found answer
            cout << tr[node].second << endl;
            cout << static_cast<ll>(round(tr[node].first/3)) << endl;
            break;
        }

        if (t>tr[node].first) {
            continue;
        }

        for (auto adj: graph[node]) {
            int adj_node = adj.first;
            double adj_t = adj.second;

            //if found new shortest time -> guarenteed new path
            if (t+adj_t < tr[adj_node].first) {
                tr[adj_node].first = t+adj_t;
                tr[adj_node].second = r+1;
                pq.push({tr[adj_node], adj_node});
            //else if same time but less roads 
            } else if (t+adj_t == tr[adj_node].first) {
                //then new path
                if (r+1<tr[adj_node].second) {
                    tr[adj_node].second = r+1;
                    pq.push({tr[adj_node], adj_node});
                }
            }
        }

    }


    return 0;
}

