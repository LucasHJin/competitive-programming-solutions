#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> people(n);
    for (int i=0; i<n; i++) {
        cin >> people[i];
    }

    int partition;
    for (int i=0; i<d; i++) {
        cin >> partition;

        //recalculate prefix sum
        vector<int> prefix(people.size());
        prefix[0] = people[0];
        for (int j=1; j<people.size(); j++) {
            prefix[j] = prefix[j-1] + people[j];
        }

        /*
        TESTING
        for (auto it: people) {
            cout << it << " ";
        }
        cout << endl;
        for (auto it: prefix) {
            cout << it << " ";
        }
        cout << endl;
        */

        
        //check which is bigger
        int left_sum = prefix[partition-1];
        int right_sum = prefix[people.size()-1] - left_sum;

        if (left_sum>=right_sum) {
            cout << left_sum << endl;
            //remake the array!!!!
            people = vector<int>(people.begin()+partition, people.end());
        } else {
            cout << right_sum << endl;
            people = vector<int>(people.begin(), people.begin()+partition);
        }
    }



    return 0;
}

