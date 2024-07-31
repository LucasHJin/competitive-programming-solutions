#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

void addWeightedEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w) {
    graph[u].push_back({v, w});
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    for (int i=0; i<5; i++) {
        int n;
        cin >> n;

        vector<pair<pair<string, string>, int>> inputs(n+1);
        string c1, c2;
        int w;
        for (int j=1; j<=n; j++) {
            cin >> c1 >> c2 >> w;
            inputs[j] = {{c1, c2}, w};
        }

        unordered_map<string, int> convert;
        int ind = 1;

        for (int j=1; j<=n; j++) {
            if (convert.find(inputs[j].first.first) == convert.end()) {
                convert.emplace(inputs[j].first.first, ind);
                ind += 1;
            }
            if (convert.find(inputs[j].first.second) == convert.end()) {
                convert.emplace(inputs[j].first.second, ind);
                ind += 1;
            }
        }
        

        int l = convert.size();

        //(node 1, node 2, weight)
        vector<vector<pair<int, int>>> graph(l+1); 
        vector<int> dist(l+1, INT_MAX);
        //(weight, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int j=1; j<=n; j++) {
            c1 = inputs[j].first.first;
            c2 = inputs[j].first.second;
            w = inputs[j].second;
            addWeightedEdge(graph, convert[c1], convert[c2], w);
        }



        //YYZ to SEA
        int start = convert["YYZ"];
        int end = convert["SEA"];

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int curr_node = pq.top().second;
            int curr_w = pq.top().first;

            pq.pop();

            if (curr_node == end) {
                cout << dist[curr_node] << endl;
                break;
            }

            //if already assigned a value and the current weight is already greater than the assigned value
            if (curr_w > dist[curr_node]) continue;

            for (auto adj: graph[curr_node]) {
                int adj_node = adj.first;
                int adj_w = adj.second;

                if (curr_w + adj_w < dist[adj_node]) {
                    dist[adj_node] = curr_w + adj_w;
                    pq.push({dist[adj_node], adj_node});
                }
            }
            
        }

    }
    
    return 0;
}

