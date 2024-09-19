#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> dist(n+1, 0);

    int max = 0; 
    int sum = 0;
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sum = sum+c+c; //going there and back
        dist[b] = dist[a] + c; //distance to reach node b = node a + edge length
        if (dist[b] > max) 
            max = dist[b]; 
    }

    cout << sum - max << endl; //subtract max because you want max to be the last one so you don't have to go back

    return 0;
}

