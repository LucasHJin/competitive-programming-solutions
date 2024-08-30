#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;


int find_rep(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find_rep(parent[x], parent); 
    }
    return parent[x];
}

void union_sets(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find_rep(x, parent);
    int rootY = find_rep(y, parent);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            //if both ranks equal
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
    vector<int> rank(n, 0);

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int cell;
            cin >> cell;
            if (cell==1) {
                union_sets(i, j, parent, rank);
            }
        }
    }

    vector<vector<int>> ans(n);

    for (int i=0; i<n; i++) {
        ans[find_rep(i, parent)].push_back(i+1);
    }

    sort(ans.begin(), ans.end());

    for (int i=0; i<n; i++) {
        if (!ans[i].empty()) {
            for (auto it: ans[i]) {
                cout << it << " ";
            } cout << endl;
        }
    }

    return 0;
}