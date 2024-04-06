#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
 
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef long long int ll;
 
 
int main() {
    int n;
    cin >> n;
    string shots(n, 'o');
    for (int i=2; i<n; i+=3) {
        shots[i]='x';
    }
    cout << shots;
    
 
    return 0;
}