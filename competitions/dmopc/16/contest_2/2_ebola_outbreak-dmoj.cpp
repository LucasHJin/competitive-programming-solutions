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

    for (int i=0; i<m; i++) {
        int k;
        cin >> k;
        vector<int> people(k);
        for (int j=0; j<k; j++) {
            int temp;
            cin >> temp;
            temp--;
            people[j] = temp;
        }
        for (int j=0; j<k; j++) {
            for (int l=j+1; l<k; l++) {
                union_sets(people[j], people[l], parent, rank);
            }
        }
    }

    vector<int> ans;

    for (int i=0; i<n; i++) {
        if (find_rep(i, parent)==find_rep(0, parent)) {
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << endl;
    for (auto it: ans) {
        cout << it << " ";
    }

    
    return 0;
}