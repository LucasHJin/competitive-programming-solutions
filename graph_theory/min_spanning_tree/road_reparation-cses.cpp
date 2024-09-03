#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//disjoint union + krustal

struct Edge {
    int src, dest, weight;
};

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), comp);

    ll mst = 0;
    ll num_edges = 0;
    DisjointSet ds(n);

    for (const auto& edge: edges) {
        int u = edge.src;
        int v = edge.dest;

        if (ds.find_rep(u) != ds.find_rep(v)) { //no cycle
            //merge sets (to represent keeping edge)
            ds.union_set(u, v);
            mst += edge.weight;
            num_edges++;
            if (num_edges == n-1) {
                break; //early break if created mst
            }
        }
    }

    if (num_edges != n-1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << mst << endl;
    }

    
    return 0;
}