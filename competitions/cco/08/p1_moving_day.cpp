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

    unordered_map<int, string> convName;
    unordered_map<int, int> addToGraph;
    vector<vector<int>> adjList(101);
    unordered_map<int, int> reverseGraph;
    
    int count = 1;

    for (int i=0; i<n; i++) {
        string name;
        int x, y;
        cin >> name >> x >> y;
        convName[x] = name;
        if (addToGraph.find(x) == addToGraph.end()) {
            addToGraph[x] = count;
            count += 1;
        }
        if (addToGraph.find(y) == addToGraph.end()) {
            addToGraph[y] = count;
            count += 1;
        }
        addEdge(adjList, addToGraph[x], addToGraph[y]);
    }

    for (auto it: addToGraph) {
        reverseGraph[it.second] = it.first;
    }

    vector<int> inDegree(count);

    for (int i=1; i<count; i++) {
        for (auto prereq: adjList[i]) {
            inDegree[prereq] += 1;
        }
    }

    queue<int> togo;
    vector<int> result;
    for (int i=1; i<count; i++) {
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

    vector<string> ans;

    for (auto it: result) {
        //cout << it << " " << reverseGraph[it] << endl;

        int it2 = reverseGraph[it];
        if (convName.find(it2) != convName.end()) {
            ans.push_back(convName[it2]);
        }
    }

    if (ans.size() != n) {
        cout << "Impossible" << endl;
    } else {
        reverse(ans.begin(), ans.end());

        for (auto it: ans) {
            cout << it << endl;
        }
    }


    return 0;
}