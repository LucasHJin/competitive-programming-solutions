#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//dp + graph theory
    //dag

void addEdge(vector<vector<int>>& adjList, int x, int y) {
    adjList[x].push_back(y);
}

void topologicalSort(int v, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& togo) {
    visited[v] = true;

    for (int i: adjList[v]) {
        if (!visited[i]) {
            topologicalSort(i, adjList, visited, togo);
        }
    }

    togo.push(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adjList(n+1);
    int x=10, y=10;
    while (x!=0 and y!=0) {
        cin >> x >> y;
        addEdge(adjList, x, y);
    }

    vector<bool> visited(n+1, false);
    stack<int> togo;

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            topologicalSort(i, adjList, visited, togo);
        }
    }

    //dfs on tp sorted list
    vector<ll> dp(n+1, 0);
    dp[1] = 1;

    while (!togo.empty()) {
        int node = togo.top();
        togo.pop();

        for (auto adj: adjList[node]) {
            //add on amount of ways to get to previous to curr amount to get to node
            dp[adj] += dp[node];
        }
    }
    
    cout << dp[n] << endl;

    return 0;
}

