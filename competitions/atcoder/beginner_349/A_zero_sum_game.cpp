#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int sum=0;

    for (int i=0; i<n-1; i++) {
        int temp;
        cin >> temp;
        sum+=temp;
    }

    sum=sum*(-1);

    cout << sum << endl;
    
    return 0;
}