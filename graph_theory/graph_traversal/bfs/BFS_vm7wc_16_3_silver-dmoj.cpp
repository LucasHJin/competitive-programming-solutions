#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;




//func to add edge between two nodes in adjacency list (they are linked)
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

//func to test printing queue elements
void printQueue(queue<int> q) {
    cout << "Q ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    //adjacency list to represent which nodes are connected
    vector<vector<int>> adjList(n+1);

    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    /*
    testing adjacent list elements


    for (int i=1; i<=n; i++) {
        for (auto j: adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    */

    unordered_set<int> visited;
    queue<int> togo;

    //emplace and find
    visited.emplace(a);
    //pop and push
    togo.push(a);

    bool good = false;

    while (!togo.empty()) {
        vector<int> val = adjList[togo.front()];

        /*
        TESTING

        cout << "V ";
        for (auto i: visited) {
            cout << i << " ";
        }
        cout << endl;
        printQueue(togo);
        for (auto it: val) {
            cout << it << " ";
        }
        cout << endl;
        */

        //adding all new neighbor nodes
        for (int i=0; i<val.size(); i++) {
            if (visited.find(val[i]) == visited.end()) {
                togo.push(val[i]);
            }
        }
        //check if have reached other house
        if (togo.front() == b) {
            good = true;
            break;
        }
        //move current node to visited and remove from togo and move on
        visited.emplace(togo.front());
        togo.pop();
    }

    //answer
    if (good) {
        cout << "GO SHAHIR!" << endl;
    } else {
        cout << "NO SHAHIR!" << endl;
    }

    
    return 0;
}

