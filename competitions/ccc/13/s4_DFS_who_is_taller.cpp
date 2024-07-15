#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

//dfs

bool dfs(vector<vector<int>>& adjList, int node, int end, unordered_set<int>& visited) {
    if (node == end) {
        return true;
    }

    if (visited.find(node) == visited.end()) {
        visited.emplace(node);
        for (auto next_node: adjList[node]) {
            if (dfs(adjList, next_node, end, visited)) {
                return true;
            }
        }
    }
    
    return false;
}


void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n+1);

    int u, v;
    //person u > person v
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    int p, q;
    cin >> p >> q;
    //if p goes to q -> p>q
    //if q goes to p -> p<q
    //if no path -> not enough info

    unordered_set<int> visited;
    bool yes = false;
    bool no = false;


    yes = dfs(adjList, p, q, visited);

    if (yes) {
        cout << "yes" << endl;
    } else {
        visited.clear();

        no = dfs(adjList, q, p, visited);

        if (no) {
            cout << "no" << endl;
        } else {
            cout << "unknown" << endl;
        }
    }

    
    return 0;
}

