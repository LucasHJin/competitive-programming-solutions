#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    
    //append new one 
    //check closest above and below
    //compare to max
    //set a new max if it interferes with the previous max
    
    //only need to check if it is where the previous longest set place was
    
    set<pair<int, int>> temp;
    multiset<int> temp_length;

    temp.insert({0, x});
    temp_length.insert(x);

    for (int i=0; i<n; i++) {
        int pos = p[i];
        //both are sets -> sorted, same position in both -> can find new range length
        auto it = temp.upper_bound({pos,0});
        it--;

        int bottom = it->first;
        int top = it->second;
        //same as *(it).first
            //* is derefence operator -> access value iterator is pointing to
            //-> directly accesses elements of object that iterator is pointing at directly

        temp.erase(it);
        temp_length.erase(temp_length.find(top-bottom));

        temp.insert({bottom, pos});
        temp.insert({pos, top});

        temp_length.insert(pos-bottom);
        temp_length.insert(top-pos);

        cout << *temp_length.rbegin() << " ";

    }

    return 0;
}
