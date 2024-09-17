#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
public:
    vector<int> parent, rank, dest_count; //dest count is how many destination cities are reachable from any city

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        dest_count.resize(n, 0);
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int find_rep(int u) {
        if (u != parent[u]) {
            parent[u] = find_rep(parent[u]);
        }
        return parent[u];
    }

    void union_set(int u, int v) {
        int rootU = find_rep(u);
        int rootV = find_rep(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV; //V becomes parent
                dest_count[rootV] += dest_count[rootU]; //update the destination count for parent of union
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                dest_count[rootU] += dest_count[rootV];
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
                dest_count[rootU] += dest_count[rootV];
            }
        }
    }
};


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int c, r, d;
    cin >> c >> r >> d;
    vector<Edge> roads;
    for (int i=0; i<r; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        roads.push_back({x, y, w});
    }
    vector<int> destinations(d);
    for (int i=0; i<d; i++) {
        cin >> destinations[i];
        destinations[i]--;
    }

    sort(roads.begin(), roads.end(), comp);
    reverse(roads.begin(), roads.end()); //reverse so that heaviest roads first (left with smallest value in the end) 

    DisjointSet ds(c);
    int ans = 0;
    for (auto city: destinations) //all destination cities can reach themselves
        ds.dest_count[city] = 1;
    ds.dest_count[0] = 1;

    int total_destinations = destinations.size() + 1;

    for (auto road: roads) {
        int u = road.src;
        int v = road.dest;
        int w = road.weight;

        if (ds.find_rep(u)!=ds.find_rep(v)) { //if cities are two separate sets -> connect
            ds.union_set(u, v);

            if (ds.dest_count[ds.find_rep(0)]==total_destinations) { //if all destination cities are in one set (can check any value but 0 is guarenteed to be destination city)
                ans = w; //current road weight is answer
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}