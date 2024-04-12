#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<string> values;
    
    //needed for first iteration (to create 0 and 1)
    values.push_back("0");
    values.push_back("1");


    for (int i = 0; i < n-1; i++) {
        int sz = values.size();

        //add reverse
        for (int j=sz-1; j>=0; j--) {
            values.push_back(values[j]);
        }
        sz = values.size();

        //add 0 to first half, 1 to second half
        for (int j=0; j<sz; j++) {
            if (j<values.size() / 2) {
                values[j] += "0";
            } else {
                values[j] += "1";
            }
        }
    }

    for (auto it: values) {
        cout << it << endl;
    }

    /* FOR PRINTING BINARY/BASE TWO
    ll amount=1;
    for (int i=1; i<=n; i++) {
        amount*=2;
    }
    vector<int> value(n);
    //first value
    for (auto it: value) {
            cout << it;
        }
    cout << "\n";
    //2^n-1 values remaining
    for (ll i=0; i<(amount-1); i++) {
        for (int i=n-1; i>=0; i--) {
            if (value[i]==1) {
                continue;
            } else if (value[i]==0) {
                value[i]=1;
                i+=1;
                while (i<=(n-1)) {
                    value[i]=0;
                    i+=1;
                }
                break;
            }
        }
        for (auto it: value) {
            cout << it;
        }
        cout << "\n"; */
    
    
    

    

    return 0;
}