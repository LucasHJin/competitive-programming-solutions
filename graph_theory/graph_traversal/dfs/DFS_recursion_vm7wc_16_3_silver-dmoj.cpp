#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

//dfs is typically done with recursion because goes all the way down before coming back up


int n, m, a, b;

bool dfs(int node, unordered_set<int>& visited, vector<vector<int>>& adjList) {
    //base case -> found path
    if (node == b) {
        return true;
    }
    
    //unvisited node
    if (visited.find(node) == visited.end()) {
        visited.emplace(node);
        for (auto neighbor: adjList[node]) {
            //don't need to check if visited because will do that in recursive call
            if (dfs(neighbor, visited, adjList)) {
                //if the target node is found in any of the recursive calls, return true
                return true;
            }
        }
    }

    //if already visited node, will go to next one
    return false;
}

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> a >> b;

    vector<vector<int>> adjList(n+1);

    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    //emplace and find
    unordered_set<int> visited;
    //NO NEED FOR STACK -> the dfs will go through that automatically

    bool good = dfs(a, visited, adjList);

    if (good) {
        cout << "GO SHAHIR!" << endl;
    } else {
        cout << "NO SHAHIR!" << endl;
    }
    
    return 0;
}

