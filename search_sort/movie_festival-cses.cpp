#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
 
typedef long long ll;
 
using namespace std;


//sort by ending time -> don't have to worry about extremely long movie
bool sec(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second; //if a<b -> true -> a is first, opposite if b<a
}
//const to make sure no accidental modifications
//& for operating directly on object instead of a copy

int main() {
    int n;
    cin >> n;
    int count = 0;
    int end = 0;

    vector<pair<int, int>> movies(n);

    for (int i=0; i<n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), sec);

    //greedy
    for (int i=0; i<n; i++) {
        if (movies[i].first >= end) {
            ++count;
            end = movies[i].second;
        }
    }
    
    cout << count << endl;

    return 0;
    
}