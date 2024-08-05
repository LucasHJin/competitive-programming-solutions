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
    int n, k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> graph(k+1);
    int s, e, t;
    for (int i=1; i<=n; i++) {
        cin >> s >> e >> t;
        addEdge(graph, s, e, t);
    }

    //getting traffic light times
    vector<pair<int, int>> lights(k+1);
    int g, r;
    for (int i=1; i<=k; i++) {
        cin >> g >> r;
        lights[i] = {g, r};
    }

    vector<int> time(k+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    time[1] = 0;
    pq.push({0, 1});

    //normal dijkstra
    while (!pq.empty()) {
        int node = pq.top().second;
        int t = pq.top().first;

        pq.pop();

        
        if (node == k) {
            cout << time[k] << endl;
            break;
        }
        

        if (t>time[node]) {
            continue;
        }

        for (auto adj: graph[node]) {
            int adj_node = adj.first;
            int adj_t = adj.second;

            //finding total time passed before reaching light
            int total_time = t + adj_t;
            //finding amount of time in one green-red cycle
            int light_cycle = lights[adj_node].first + lights[adj_node].second;

            //if there is a cycle (not no lights)
            if (adj_node != k and light_cycle != 0) {

                //if the amount of time passed is greater than green (so its in red currently)
                if (total_time % light_cycle >= lights[adj_node].first) {
                    //add on remaining red time
                    total_time += light_cycle - (total_time%light_cycle);
                }
            }            
            //if new lowest time
            if (total_time < time[adj_node]) {
                time[adj_node] = total_time;
                pq.push({time[adj_node], adj_node});
            }
        }
    }

 
    return 0;
}

