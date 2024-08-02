#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_set>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, t, x, y, c, k, z, p, d;
    cin >> n;

    vector<vector<int>> graph(n+1, vector<int>(n+1, INT_MAX));

    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> x >> y >> c;
        //add to adjacency matrix?
        graph[x][y] = c;
        graph[y][x] = c;
    }
    
    vector<int> cost(n+1, 100000);

    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> z >> p;
        //add to cost list
        cost[z] = p;
    }   

    //start
    cin >> d;

    vector<bool> visited(n+1, false);
    vector<int> answers(n+1, INT_MAX);
    answers[d] = 0;

    for (int i=1; i<=n; i++) {
        //find current smallest unvisited node
        int min_node = 0;
        for (int j=0; j<=n; j++) {
            if (!visited[j] and answers[j]<answers[min_node]) {
                min_node = j;
            }
        }

        //if is visited, all have been processed
        if (visited[min_node]) {
            break;
        }

        //mark as visited
        visited[min_node] = true;

        //go through the graph for the node
        for (int j=1; j<=n; j++) {
            //if there is a connection
            if (graph[min_node][j] != INT_MAX) {
                //check if value from connection creates smaller than current connection
                if (answers[min_node] + graph[min_node][j] < answers[j]) {
                    answers[j] = answers[min_node] + graph[min_node][j];
                }
            }
        }
    }

    //can add on prices at the end because they don't conflict with each other
        //ie. if at city B, prices from city A don't affect it
    int fin_cost = INT_MAX;
    for (int i=1; i<=n; i++) {
        fin_cost = min(answers[i]+cost[i], fin_cost);
    }
    
    cout << fin_cost << endl;

    return 0;
}