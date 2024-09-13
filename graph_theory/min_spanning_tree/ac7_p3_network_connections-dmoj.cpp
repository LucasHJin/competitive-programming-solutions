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
    vector<int> f(n);
    for (int i=0; i<n; i++) {
        cin >> f[i];
    }
    vector<Edge> edges;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.push_back({a, b, 0});
    }
    for (int i=0; i<n-1; i++) {
        edges.push_back({i, i+1, abs(f[i+1]-f[i])});
    }
    sort(edges.begin(), edges.end(), comp);
    DisjointSet ds(n);
    int num = 0;
    int cost = 0;

    for (auto edge: edges) {
        int u = edge.src;
        int v = edge.dest;

        if (ds.find_rep(u)!=ds.find_rep(v)) {
            ds.union_set(u, v);
            num += 1;
            cost += edge.weight;
            if (num==n-1) {
                break;
            }
        }
    }

    cout << cost << endl;

    return 0;
}