#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

//bfs

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adjList(n+1);
    unordered_set<int> endings;

    int m;
    int temp;
    for (int i=1; i<=n; i++) {
        cin >> m;
        if (m==0) {
            endings.emplace(i);
        } else {
            for (int j=0; j<m; j++) {
                cin >> temp;
                addEdge(adjList, i, temp);
            }
        }
    }

    /*
    for (int i=1; i<=n; i++) {
        for (auto it: adjList[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
    */

    queue<int> togo;
    unordered_set<int> visited;
    vector<int> path_len(n+1, INT_MAX);

    path_len[1]=1;
    visited.emplace(1);
    togo.push(1);

    vector<int> vals;
    while (!togo.empty()) {
        int curr_node = togo.front();

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

    /*
    for (auto it: path_len) {
        cout << it << " ";
    }
    */

    int shortest = INT_MAX;
    int all = true;

    for (auto it=endings.begin(); it!=endings.end(); it++) {
        shortest = min(shortest, path_len[*it]);
    }

    for (int i=1; i<=n; i++) {
        if (path_len[i]==INT_MAX) {
            all = false;
        }
    }

    if (all) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
    cout << shortest << endl;



    
    return 0;
}

