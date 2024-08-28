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

void union_sets(int x, int y, vector<int>& parent, vector<int>& rank, vector<int>& size) {
    int rootX = find_rep(x, parent);
    int rootY = find_rep(y, parent);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            //if both ranks equal
            parent[rootY] = rootX;
            rank[rootX]++;
            size[rootX] += size[rootY];
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
    vector<int> rank(n, 0);
    vector<int> size(n, 1); //size of each subtree
    for (int i=0; i<q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            union_sets(x, y, parent, rank, size);
        } else {
            int x;
            cin >> x;
            x--;
            cout << size[find_rep(x, parent)] << endl; //size of the tree which starts with the representative of the tree that contains x
        }
    }


    return 0;
}