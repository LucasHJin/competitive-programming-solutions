#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adjList(n);
    for (int i=0; i<m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, -w});
    }

    vector<ll> ans(n, LLONG_MAX);

    for (int i=0; i<n; i++) {
        if (ans[i]==LLONG_MAX) {
            unordered_set<int> visited;
            queue<pair<int, ll>> togo;

            visited.emplace(i);
            togo.push({i, 0});
            ans[i] = 0;

            vector<pair<int, ll>> vals;
            while (!togo.empty()) {
                pair<int, ll> curr_node = togo.front();
                int cv = curr_node.first;
                ll cw = curr_node.second;

                togo.pop();

                vals = adjList[cv];
                for (auto next: vals) {
                    int nextv = next.first;
                    ll nextw = next.second;
                    //cout << nextv+1 << " " << nextw << endl;
                    if (visited.find(nextv) == visited.end()) {
                        visited.emplace(nextv);
                        ans[nextv] = nextw+cw;
                        togo.push({nextv, ans[nextv]});
                    }
                }
            }
        }
    }

    for (auto it: ans) {
        cout << it << " ";
    }

    return 0;
}

