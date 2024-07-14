#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //num of lines (nodes), start, end, num of escalators (edges)
    int l, a, b, n;
    cin >> l >> a >> b >> n;

    vector<vector<int>> adjList(n+1);

    int u, v;
    for (int i=1; i<=n; i++) {
        cin >> u >> v;
        //only from u to v and not vice versa
        addEdge(adjList, u, v);
    }

    queue<int> togo;
    unordered_set<int> visited;
    vector<int> path_len(n+1, INT_MAX);

    //starting point is 0
    path_len[a]=0;
    visited.emplace(a);
    togo.push(a);

    
    vector<int> vals;
    while (!togo.empty()) {
        int curr_node = togo.front();

        if (curr_node == b) {
            cout << path_len[b] << endl;
            break;
        }
        togo.pop();

        vals = adjList[curr_node];
        for (auto next: vals) {
            if (visited.find(next) == visited.end()) {
                togo.push(next);
                visited.emplace(next);
                path_len[next] = path_len[curr_node] + 1;
            }
        }
    }

    
    return 0;
}

