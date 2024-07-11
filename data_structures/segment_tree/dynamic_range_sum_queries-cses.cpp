#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//O(n)
void construct(vector<int> inp, int cur_node, int arr_l, int arr_r, int segtree[]) {
    if (arr_l == arr_r) {
        //if current node represents inp single element in the input array -> set to that value (leaf)
        segtree[cur_node] = inp[arr_l];
    } else { //represents more than 1 value
        //middle index 
        int arr_m = (arr_l + arr_r) / 2;
        //constructing left child (at place i*2)
        construct(inp, cur_node*2, arr_l, arr_m, segtree);
        //constructing right child (at place i*2+1)
        construct(inp, cur_node*2+1, arr_m+1, arr_r, segtree);
        //can now give value to the current node because you recursively constructed the child nodes already
        segtree[cur_node] = segtree[cur_node*2] + segtree[cur_node*2+1];
    }
}

//O(logn)
ll sum(int cur_node, int arr_l, int arr_r, int query_l, int query_r, int segtree[]) {
    if (query_l > query_r) 
        //if invalid query
        return 0;
    if (query_l == arr_l && query_r == arr_r) {
        //if current segment = queried segment
        return segtree[cur_node];
    }
    //middle
    int arr_m = (arr_l + arr_r) / 2;
    //will do 2 recursive calls even if only 1 is necessary because then query_l>query_r will remove the invalid call
        //current node tells us which value in the segment tree to return (then they are all added up)
    return sum(cur_node*2, arr_l, arr_m, query_l, min(query_r, arr_m), segtree) + sum(cur_node*2+1, arr_m+1, arr_r, max(query_l, arr_m+1), query_r, segtree);
}

//O(logn)
void update(int cur_node, int arr_l, int arr_r, int upd_pos, int new_val, int segtree[]) {
    if (arr_l == arr_r) {
        //if the left and right of segment are same -> leaf node, can set new value
        segtree[cur_node] = new_val;
    } else {
        //middle
        int arr_m = (arr_l + arr_r) / 2;
        //only need to update one side (other side will remain same because updating 1 value)
        if (upd_pos <= arr_m)
            //if updating left child (will only change actual value for leaf) -> all the rest is added up
            update(cur_node*2, arr_l, arr_m, upd_pos, new_val, segtree);
        else
            //if updating right child
            update(cur_node*2+1, arr_m+1, arr_r, upd_pos, new_val, segtree);
        //calculate value based on new value for 1 of the children
        segtree[cur_node] = segtree[cur_node*2] + segtree[cur_node*2+1];
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    
    int seg[4*n]; //will be filled with random nums to take up memory
    construct(x, 1, 0, x.size()-1, seg);
    /*
    for (int i=1; i<4*n; i++) {
        cout << seg[i] << " ";
    }
    */
    int a, b, c;
    for (int i=0; i<q; i++) {
        cin >> a >> b >> c;
        if (a==1) {
            b--;
            update(1, 0, x.size()-1, b, c, seg);
        } else {
            b--;
            c--;
            //current node starts at 1 because start at root and go down from there
            cout << sum(1, 0, x.size()-1, b, c, seg) << endl;
        }
    }

    return 0;
}

