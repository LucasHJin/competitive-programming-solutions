#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<ll> hold;
   
    for (int i=0; i<n; i++ ) {
        ll a, b;
        cin >> a >> b;
        //x+2y=a, 2y+x=b
        //x=(2b-a)/3, y=(2a-b)/3
        if ((2*b-a)%3==0 and (2*b-a)>=0 and (2*a-b)%3==0 and (2*a-b)>=0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}