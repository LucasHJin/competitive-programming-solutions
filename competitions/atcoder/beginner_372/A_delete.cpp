#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;
    str.erase(std::remove(str.begin(), str.end(), '.'), str.end());

    cout << str << endl;
    
    return 0;
}

