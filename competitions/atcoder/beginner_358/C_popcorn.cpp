#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);

    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    //o good
    //x bad

    vector<set<int>> flavors(n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j]=='o') {
                flavors[i].insert(j);
            }
        }
    }
    
    //all chosen
    
    set<int> all_flavors;
    for (int i=0; i<m; i++) {
        all_flavors.insert(i);
    }


    int min_s = INT_MAX;

    //defined inside to provide access to variables
    //iterate through to check all possible permutations
    function<void(int, int, set<int>)> explore = [&](int current_stand, int chosen_count, set<int> covered_flavors) {
        if (current_stand==n) {
            //base case
            if (covered_flavors==all_flavors) {
                min_s = min(min_s, chosen_count);
            }
            return;
        }

        //include
        set<int> new_covered = covered_flavors;
        for (int flavor: flavors[current_stand]) {
            new_covered.insert(flavor);
        }
        explore(current_stand+1, chosen_count+1, new_covered);

        //dont include
        explore(current_stand+1, chosen_count, covered_flavors);
    };

    set<int> covered_flavors;
    explore(0, 0, covered_flavors);

    cout << min_s << endl;

    return 0;
}
