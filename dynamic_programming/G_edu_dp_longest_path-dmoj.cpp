#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//is a dag (directed acrylic graph)
    //edges have a direction + no cycle
    //can be topologically sorted


void addEdge(vector<vector<int>>& adjList, int x, int y) {
    adjList[x].push_back(y);
}

void topologicalSort(int v, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& togo) {
    //dfs based tpsort
        //a topological sort is one where every for every directed edge (u, v), u comes before v

    visited[v] = true;
    
    //for each univisited vertex, perform a dfs to go down to the very bottom
        //that way if u1 leads to v1=u2, u2 will lead to v2 instead of having another v1
    for (int i: adjList[v]) {
        if (!visited[i]) {
            topologicalSort(i, adjList, visited, togo);
        }
    }

    togo.push(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n+1);

    int x, y;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        addEdge(adjList, x, y);
    }  

    stack<int> togo;
    vector<bool> visited(n+1, false);

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            topologicalSort(i, adjList, visited, togo);
        }
    }

    vector<int> dp(n+1, 0);

    //go through the togo (has already been sorted) - so you visit all in proper order
    while (!togo.empty()) {
        int u = togo.top();
        togo.pop();
        
        //for each adjacent vertex
        for (int v: adjList[u]) {
            dp[v] = max(dp[v], dp[u]+1);
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    
}

