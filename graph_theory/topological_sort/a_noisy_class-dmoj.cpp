#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<int>>& adjList, int x, int y) {
    //check for duplicates (nondistinct edges)
    if (find(adjList[x].begin(), adjList[x].end(), y) == adjList[x].end()) {
        adjList[x].push_back(y);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> adjList(n+1);


    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;

        addEdge(adjList, x, y);

    }

    vector<int> inDegree(n+1, 0);

    for (int i=1; i<=n; i++) {
        for (auto prereq: adjList[i]) {
            inDegree[prereq] += 1;
        }
    }

    queue<int> togo;
    vector<int> result;
    for (int i=1; i<=n; i++) {
        if (inDegree[i] == 0) {
            togo.push(i);
        }
    }

    while (!togo.empty()) {
        int node = togo.front();
        result.push_back(node);
        togo.pop();

        for (auto adj_node: adjList[node]) {
            inDegree[adj_node] -= 1;
            if (inDegree[adj_node] == 0) {
                togo.push(adj_node);
            }
        }
    }

    if (result.size() == n) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }



    return 0;
}