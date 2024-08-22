#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//simpler top sort + cycle check of j4
    //using pq still

void addEdge(vector<vector<int>>& adjList, int x, int y) {
    adjList[x].push_back(y);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    vector<int> inDegree(8);
    vector<vector<int>> adjList(8);
    adjList[1].push_back(7);
    adjList[1].push_back(4);
    adjList[2].push_back(1);
    adjList[3].push_back(4);
    adjList[3].push_back(5);
    inDegree[7]++;
    inDegree[4]++;
    inDegree[1]++;
    inDegree[4]++;
    inDegree[5]++;

    int x, y;
    cin >> x >> y;
    while (x!=0 and y!=0) {
        adjList[x].push_back(y);
        inDegree[y]++;
        cin >> x >> y;
    }

    //add 0 to queue
    //type, underlying storage container, comparator
        //will thus go through the smallest ones before the biggest ones
    priority_queue<int, vector<int>, greater<int>> togo;
    vector<int> result;
    for (int i=1; i<=7; i++) {
        if (inDegree[i] == 0) {
            togo.push(i);
        }
    }

    //track results
    while (!togo.empty()) {
        int node = togo.top();
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
    if (result.size() != 7) {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    } else {
        for (auto it: result) {
            cout << it << " ";
        }
    }
    
    return 0;
}

