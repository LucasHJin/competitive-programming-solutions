#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int search(vector<int>& nums, int target, int min_i, int max_i) {
    int check = (min_i+max_i)/2;
    
    //base case
    if (min_i > max_i) {
        return -1; 
    }

    //normal logic
    if (nums[check]==target) {
        return check;
    } else if (nums[check]>target) {
        return search(nums, target, min_i, check-1); //search below
    } else {
        return search(nums, target, check+1, max_i); //search above
    }
}

int main() {
    int target, len;
    vector<int> values;
    cin >> len >> target;

    for (int i=0; i<len; i++) {
        int temp;
        cin >> temp;
        values.push_back(temp);
    }

    sort(values.begin(), values.end());

    int min = 0;
    int max = values.size()-1;

    int answer = search(values, target, min, max);
    cout << answer << endl;
    
    return 0;
}