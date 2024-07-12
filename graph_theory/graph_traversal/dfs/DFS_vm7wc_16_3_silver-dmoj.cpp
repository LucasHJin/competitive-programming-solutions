#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void printStack(stack<int> s) {
    cout << "S ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> adjList(n+1);

    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    //emplace and find
    unordered_set<int> visited;
    //pop, push, top
    stack<int> togo;

    visited.emplace(a);

    vector<int> vals = adjList[a];
    for (auto val: vals) {
        if (visited.find(val) == visited.end()) {
            togo.emplace(val);
        }
    }

    int good = false;

    while (!togo.empty()) {
        //if found desired value
        if (togo.top() == b) {
            good = true;
            break;
        }

        //move onto next node
        int next = togo.top();
        visited.emplace(next);
        togo.pop();


        vals = adjList[next];
        //adding all new neighbor nodes to togo
        for (int i=0; i<vals.size(); i++) {
            if (visited.find(vals[i]) == visited.end()) {
                togo.push(vals[i]);
            }
        }

    }

    if (a==b) {
        good = true;
    }

    if (good) {
        cout << "GO SHAHIR!" << endl;
    } else {
        cout << "NO SHAHIR!" << endl;
    }


    
    return 0;
}

