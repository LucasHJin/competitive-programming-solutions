#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;


int find_rep(int x, vector<pair<int, ll>>& parent) {
    if (parent[x].first != x) {
        parent[x].first = find_rep(parent[x].first, parent); 
    }
    return parent[x].first;
}

void union_sets(int x, int y, vector<pair<int, ll>>& parent, vector<int>& rank, vector<int>& size) {
    int rootX = find_rep(x, parent);
    int rootY = find_rep(y, parent);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY].first = rootX;
            parent[rootX].second += parent[rootY].second;
            size[rootX] += size[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX].first = rootY;
            parent[rootY].second += parent[rootX].second;
            size[rootY] += size[rootX];
        } else {
            parent[rootY].first = rootX;
            parent[rootX].second += parent[rootY].second;
            rank[rootX]++;
            size[rootX] += size[rootY];
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, ll>> parent(n);
    for (int i=0; i<n; i++) {
        parent[i].first = i;
        int a;
        cin >> a;
        parent[i].second = a;
    }
    vector<int> rank(n, 0);
    vector<int> size(n, 1);
    vector<int> results;

    for (int i=0; i<q; i++) {
        int c;
        cin >> c;
        if (c==1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            union_sets(x, y, parent, rank, size);
        } else if (c==2) {
            int x;
            cin >> x;
            x--;
            results.push_back(size[find_rep(x, parent)]);
        } else {
            int x;
            cin >> x;
            x--;
            results.push_back(parent[find_rep(x, parent)].second);
        }
    }

    for (auto it: results) {
        cout << it << endl;
    }

    return 0;
}