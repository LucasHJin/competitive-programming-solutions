#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//topological sort with priority queue + cycle checking

void addEdge(vector<vector<int>>& adjList, int x, int y) {
    adjList[x].push_back(y);
}

void topologicalSort(vector<vector<int>>& adjList, vector<int>& incEdgeNum, vector<int>& result) {
    //pq so that smallest number task chosen first
    priority_queue<int, vector<int>, greater<int>> pq;

    //which nodes to start with
    for (int i=1; i<=7; i++) {
        if (incEdgeNum[i] == 0) {
            pq.push(i);
        }
    }

    //while there are still nodes to go through
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        result.push_back(node);

        for (int adj_node: adjList[node]) {
            incEdgeNum[adj_node]--;
             //if the number of incoming edges becomes (0) -> checked all previous nodes
                //can now be added
            if (incEdgeNum[adj_node] == 0) {
                pq.push(adj_node);
            }
        }
    }
}


bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& recursionCheck) {
    visited[node] = true;
    //keeps track of nodes in the current DFS path
    recursionCheck[node] = true;

    for (int adj_node: adjList[node]) {
        //if detects cycle through the recursive dfs calls (from the else if)
        if (!visited[adj_node] and dfs(adj_node, adjList, visited, recursionCheck)) {
            return true; 
        //if adj_node is already in the current dfs path
        } else if (recursionCheck[adj_node]) {
            return true; 
        }
    }

    //return to previous node
    recursionCheck[node] = false; //backtrack (because only checking for the cycle for a certain segment so if exited, no longer true)
    return false; //no cycle detected
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    vector<pair<int, int>> additional;
    vector<vector<int>> adjList(8);
    adjList[1].push_back(7);
    adjList[1].push_back(4);
    adjList[2].push_back(1);
    adjList[3].push_back(4);
    adjList[3].push_back(5);

    //keep track of the number of incoming edges for each task
    vector<int> incEdgeNum(8, 0);
    incEdgeNum[7]++;
    incEdgeNum[4]++;
    incEdgeNum[1]++;
    incEdgeNum[4]++;
    incEdgeNum[5]++;

    int x, y;
    cin >> x >> y;
    while (x!=0 and y!=0) {
        adjList[x].push_back(y);
        incEdgeNum[y]++;
        cin >> x >> y;
    }

    //check if infinite loop -> if yes -> there is a problem
    
    vector<bool> visited(8, false);
    vector<bool> recursionCheck(8, false);

    bool hasCycle = false;
    for (int i=1; i<=7; i++) {
        if (!visited[i]) {
            if (dfs(i, adjList, visited, recursionCheck)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    } else {
        //printing out correct order
        vector<int> result;
        topologicalSort(adjList, incEdgeNum, result);

        for (int task: result) {
            cout << task << " ";
        }
        cout << endl;
    }


    
    return 0;
}

