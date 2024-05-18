#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;
    ll start = 1;
    ll add = 2;
    int count = 1;

    while (n>=start){
        start+=add;
        add*=2;
        count+=1;
    }

    cout << count << endl;


    return 0;
} 