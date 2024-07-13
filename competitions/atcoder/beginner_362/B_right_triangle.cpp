#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    //vectors
    int ABx = x2-x1;
    int ABy = y2-y1;
    int BCx = x3-x2;
    int BCy = y3-y2;
    int CAx = x1-x3;
    int CAy = y1-y3;

    //dot products
    ll AC = ABx*BCx + ABy*BCy;
    ll BA = BCx*CAx + BCy*CAy;
    ll CB = CAx*ABx + CAy*ABy;

    if (AC==0 or BA==0 or CB==0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

