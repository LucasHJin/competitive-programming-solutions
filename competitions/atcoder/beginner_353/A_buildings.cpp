#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height(n);

    for (int i=0; i<n; i++) {
        cin >> height[i];
    }

    int first = height[0];
    int ind = -10;

    for (int i=0; i<n; i++) {
        if (first<height[i]) {
            ind = i+1;
            break;
        }
    }

    if (ind!=-10) {
        cout << ind << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
} 