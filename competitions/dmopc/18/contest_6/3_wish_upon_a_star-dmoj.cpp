#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//disjoint union + acyclic graph checking

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
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
    vector<int> rank(n, 0);

    int cycle = 0;

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int rX = find_rep(x, parent);
        int rY = find_rep(y, parent);

        if (rX==rY) {
            //if both same parent -> linked to each other -> cycle exists
            cycle += 1;
        } else {
            union_sets(x, y, parent, rank); //only add link if no cycle so not redundant and easier to track future cycles
        }
    }

    if (cycle<=1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    
    return 0;
}