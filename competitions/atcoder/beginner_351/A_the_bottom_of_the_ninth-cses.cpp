#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

int main() {
    int a=0, b=0;
    for (int i=0; i<9; i++) {
        int temp;
        cin >> temp;
        a+=temp;
    }
    for (int i=0; i<8; i++) {
        int temp;
        cin >> temp;
        b+=temp;
    }
    int amount = a-b+1;
    cout << amount << endl;
    
    return 0;
}