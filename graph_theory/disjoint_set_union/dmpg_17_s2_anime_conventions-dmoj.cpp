#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

//checking for if there are connected edges

//finds the parent of the set that contains a certain element
    //can check if both in same set to see if there is a path between them 
        //(one will always fall under the other set if connection exists)
int find_rep(int x, vector<int>& parent) {
    //will only stay as its own index if always parent
        //go until find the index where this is the case
    if (parent[x] != x) {
        parent[x] = find_rep(parent[x], parent); //path compression
    }
    return parent[x];
}

//function to combine two sets which contain elements x and y
    //used mainly to add edge between two elements
void union_sets(int x, int y, vector<int>& parent, vector<int>& rank) {
    //find which set
    int rootX = find_rep(x, parent);
    int rootY = find_rep(y, parent);

    //set merging logic 
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
    int n, q;
    cin >> n >> q;
    char letter;
    int x, y;

    //represents parent root of each element in the set
        //initially, each own set -> so own parent
        //when merge -> root of 1 becomes child of root of other (point to other root)
            //eventually forms a tree -> all pointing to parents
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    //used to keep the tree representing each set as shallow as possible
        //depth of tree at each element (initially 0)
        //when merge -> root with smaller rank under bigger rank
            //if equal rank -> one becomes parent and rank += 1
    vector<int> rank(n, 0);
    for (int i=0; i<q; i++) {
        cin >> letter >> x >> y;
        if (letter=='A') {
            union_sets(x, y, parent, rank);
        } else {
            if (find_rep(x, parent)==find_rep(y, parent)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }


    return 0;
}