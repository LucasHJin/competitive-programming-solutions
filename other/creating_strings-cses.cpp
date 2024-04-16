#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

//need sets -> ordered (by alphabetical) + only unique

//& passing by reference (values are modified)
void generate(set<string> &ans, string n, int l, int r) {
    //base case
    if (l==r) { 
        ans.insert(n);
        return; 
    } 
    for (int i=l; i<=r; i++) { 
        //swap
        swap(n[l], n[i]);
        //go onto creating next value
        generate(ans, n, l+1, r); 
        //go back
        swap(n[l], n[i]);

    } 
}

int main()
{
    string n;
    cin >> n;
    set<string> ans;
    int end=n.length()-1;
    generate(ans, n, 0, end);

    cout << ans.size() << endl;
    for (auto it: ans) {
        cout << it << endl;
    }
    
    return 0;
}