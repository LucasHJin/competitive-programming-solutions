#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
typedef long long ll;
 
using namespace std;

//sliding window max & min

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int m, l, n;
    cin >> m >> l >> n;
    vector<int> samples(m);
    for (int i=0; i<m; i++) {
        cin >> samples[i];
    }

    deque<int> maxDeque, minDeque; //2 windows -> track min and max
    vector<int> result;

    //go through all samples
    for (int i=0; i<m; i++) {
        //remove out of window elements (oldest is outside current window i-l)
        if (!maxDeque.empty() && maxDeque.front() <= i-l) {
            maxDeque.pop_front();
        }
        if (!minDeque.empty() && minDeque.front() <= i-l) {
            minDeque.pop_front();
        }

        //maintain order (decreasing, increasing)
        while (!maxDeque.empty() && samples[maxDeque.back()] <= samples[i]) {  //sample at back is smaller than current
            maxDeque.pop_back(); 
        }
        maxDeque.push_back(i);
        while (!minDeque.empty() && samples[minDeque.back()] >= samples[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i); //push, if it is smaller than a new max, it will be removed

        //if valid window of size l
        if (i>=l-1) {
            int maxInWindow = samples[maxDeque.front()]; //leftmost = max value
            int minInWindow = samples[minDeque.front()]; //leftmost = min value
            if (maxInWindow-minInWindow <= n) {
                result.push_back(i-l+1);  //store starting index of window
            }
        }
    }

    if (result.empty()) { //no answers
        cout << "NONE" << "\n";
    } else {
        for (auto it: result) {
            cout << it+1 << "\n";  
        }
    }


    return 0;
}

