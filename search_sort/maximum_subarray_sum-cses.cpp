#include <bits/stdc++.h>
#include <iostream>
#include <set>
 
typedef long long ll;
 
using namespace std;

//kadane's algorithm
//the local maximum at index i is the maximum of:
//(A[i] and the sum of A[i] and local maximum at index i-1) -> because adding only 1 term per i
//So, given original max, it must either be that plus the added term or 
//(if original term was large neg), is added term

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    ll overall_max = arr[0];
    ll local_max = arr[0];
    

    for (int i=1; i<n; i++) {
        local_max = max(arr[i], arr[i]+local_max);
        overall_max = max(overall_max, local_max);
    }

    cout << overall_max << endl;

    return 0;
}