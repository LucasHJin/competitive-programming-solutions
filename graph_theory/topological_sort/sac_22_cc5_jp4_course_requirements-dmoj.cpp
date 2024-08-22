#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<int>>& adjList, int x, int y) {
    adjList[x].push_back(y);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adjList(n+1);
    for (int i=1; i<=n; i++) {
        int c;
        cin >> c;
        for (int j=0; j<c; j++) {
            int prereq; 
            cin >> prereq;
            addEdge(adjList, prereq, i);
        }
    }

    //create in degree
    vector<int> inDegree(n+1);

    //increment destinations
    for (int i=1; i<=n; i++) {
        for (auto prereq: adjList[i]) {
            inDegree[prereq] += 1;
        }
    }

    //add 0 to queue
    queue<int> togo;
    vector<int> result;
    for (int i=1; i<=n; i++) {
        if (inDegree[i] == 0) {
            togo.push(i);
        }
    }

    //track results
    while (!togo.empty()) {
        int node = togo.front();
        result.push_back(node);
        togo.pop();

        //decrement + add 0 to queue again
        for (auto adj_node: adjList[node]) {
            inDegree[adj_node] -= 1;
            if (inDegree[adj_node] == 0) {
                togo.push(adj_node);
            }
        }
    }

    //answer
    for (auto it: result) {
        cout << it << " ";
    }
    
    return 0;
}

