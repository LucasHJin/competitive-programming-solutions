#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//kahn's -> implicit cycle handling
    //dfs top sort is better for explicit cycle handling

void addEdge(vector<vector<int>>& adjList, int x, int y) {
    adjList[x].push_back(y);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adjList(2000);
    unordered_map<string, int> nameConv;
    string a, b;
    int count = 1;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        if (nameConv.find(a) == nameConv.end()) {
            nameConv[a] = count;
            count++;
        }
        if (nameConv.find(b) == nameConv.end()) {
            nameConv[b] = count;
            count++;
        }
        //reverse because b is dependent on a (not reverse)
        addEdge(adjList, nameConv[b], nameConv[a]);
    }

    unordered_map<int, string> nameConv2;
    for (const auto& pair: nameConv) {
        nameConv2[pair.second] = pair.first;
    }

    count--;

    vector<int> inDegree(count+1);

    for (int i=1; i<=count; i++) {
        for (auto prereq: adjList[i]) {
            inDegree[prereq] += 1;
        }
    }

    priority_queue<int, vector<int>, greater<int>> togo;
    vector<int> result;
    for (int i=1; i<=count; i++) {
        if (inDegree[i] == 0) {
            togo.push(i);
        }
    }

    while (!togo.empty()) {
        int node = togo.top();
        result.push_back(node);
        togo.pop();

        for (auto adj_node: adjList[node]) {
            inDegree[adj_node] -= 1;
            if (inDegree[adj_node] == 0) {
                togo.push(adj_node);
            }
        }
    }

    for (auto it: result) {
        cout << nameConv2[it] << endl;
    }

    
    return 0;
}

