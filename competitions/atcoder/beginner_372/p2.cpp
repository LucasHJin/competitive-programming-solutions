#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int m;
    cin >> m;
    for (int n=1; n<=20; n++) {
        vector<int> a(n, 0);  
        int remaining = m;
        for (int i=0; i<n; i++) {
            //cout << remaining << endl;
            int val = 1;
            int counter = 0;
            while (val<remaining){
                val *= 3;
                counter += 1;
            }
            if (val!=remaining) {
                val /= 3;
                counter -= 1;
            }
            remaining -= val;
            a[i] = counter;
            //cout << val << endl;
        }
        if (remaining==0) {
            cout << n << endl;
            for (int i=0; i<n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            break;
        }
    }


    return 0;
}

