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

    queue<int> togo;
    unordered_set<int> visited;
    bool yes = false;
    bool no = false;

    visited.emplace(p);
    togo.push(p);

    vector<int> vals;
    while (!togo.empty()) {
        int curr_node = togo.front();

        if (curr_node == q) {
            yes = true;
            break;
        }

        togo.pop();

        vals = adjList[curr_node];
        for (auto next: vals) {
            if (visited.find(next) == visited.end()) {
                togo.push(next);
                visited.emplace(next);
            }
        }
    }

    if (yes) {
        cout << "yes" << endl;
    } else {
        //empty to redo
        while (!togo.empty()) {
            togo.pop();
        }
        visited.clear();

        visited.emplace(q);
        togo.push(q);

        vector<int> vals;
        while (!togo.empty()) {
            int curr_node = togo.front();

            if (curr_node == p) {
                no = true;
                break;
            }

            togo.pop();

            vals = adjList[curr_node];
            for (auto next: vals) {
                if (visited.find(next) == visited.end()) {
                    togo.push(next);
                    visited.emplace(next);
                }
            }
        }

        if (no) {
            cout << "no" << endl;
        } else {
            cout << "unknown" << endl;
        }
    }


    


    
    return 0;
}

