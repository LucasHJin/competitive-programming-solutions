#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

//shortest path -> bfs

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; //graph from 1 to n
    cin >> n;
    vector<vector<int>> adjList(n+1);

    //change input adjacency matrix to adjacency list
    int temp;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> temp;
            if (temp==1) {
                addEdge(adjList, i, j);
            }
        }
    }

    queue<int> togo;
    unordered_set<int> visited;
    vector<int> path_len(n+1, INT_MAX);
    //starting point is 0
    path_len[1]=0;

    visited.emplace(1);
    togo.push(1);

    vector<int> vals;

    while (!togo.empty()) {
        //get current node for actions like finding future nodes
        int curr_node = togo.front();

        if (curr_node == n) {
            cout << path_len[n] << endl;
            break;
        }

        //removing current ndoe
        togo.pop();

        vals = adjList[curr_node];

        //adding neighbors
        for (int i=0; i<vals.size(); i++) {
            int next_node = vals[i];
            if (visited.find(next_node) == visited.end()) {
                togo.push(next_node);
                visited.emplace(next_node);
                //based on previous path length, you're moving one more 
                path_len[next_node] = path_len[curr_node] + 1;
            }
        }

    }
    
    return 0;
}

