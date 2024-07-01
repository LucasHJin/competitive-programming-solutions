#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

vector<string> good;

void perm_gen(string& str_inp, int l, int r) {
    //base case
    if (l==r) 
        good.push_back(str_inp);
    else { //make permutation
        for (int i=l; i<=r; i++) { 
            //swap the values at the two indexes (guarenteed unique)
            swap(str_inp[l], str_inp[i]); 
            //generate a permutation based on this
            perm_gen(str_inp, l + 1, r); 
            //unswap to go to next permutation 
            swap(str_inp[l], str_inp[i]); 
        } 
    } 
} 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string inp;
    cin >> inp;
    perm_gen(inp, 0, inp.size()-1);
    sort(good.begin(), good.end());
    for (auto it: good) {
        cout << it << endl;
    }
    return 0;
}

