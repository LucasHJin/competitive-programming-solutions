#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

const int MAXN = 101;
int a[MAXN][MAXN][MAXN];
int pre[MAXN][MAXN][MAXN];

void build_prefix_sum(int n) {
    for (int x=1; x<=n; x++) {
        for (int y=1; y<=n; y++) {
            for (int z=1; z<=n; z++) {
                pre[x][y][z] = a[x][y][z] //add current node
                    + pre[x-1][y][z] //add from (1,1,1) to (x-1,y,z) (extending height)
                    + pre[x][y-1][z]
                    + pre[x][y][z-1]
                    - pre[x-1][y-1][z] //subtract overlap (i.e. (1,1,1) to (x-1,y-1,z))
                    - pre[x-1][y][z-1]
                    - pre[x][y-1][z-1]
                    + pre[x-1][y-1][z-1]; //add back subtracted part
            }
        }
    }
}


int query_sum(int lx, int rx, int ly, int ry, int lz, int rz) {
    int result = pre[rx][ry][rz]; //sum of (1,1,1) to (rx,ry,rz)
    
    //subtract unwanted parts (start at L so if L=3, don't need L=2, 1, etc.)
    if (lx>1) 
        result -= pre[lx-1][ry][rz];
    if (ly>1) 
        result -= pre[rx][ly-1][rz];
    if (lz>1) 
        result -= pre[rx][ry][lz-1];
    
    //add back because of overlap when subtracting
    if (lx>1 and ly>1) 
        result += pre[lx-1][ly-1][rz];
    if (lx>1 and lz>1) 
        result += pre[lx-1][ry][lz-1];
    if (ly>1 and lz>1) 
        result += pre[rx][ly-1][lz-1];
    
    //subtract intersection of all 3 (so no double counting)
    if (lx>1 and ly>1 and lz>1) 
        result -= pre[lx-1][ly-1][lz-1];
    
    return result;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    for (int x=1; x<=n; x++) {
        for (int y =1; y <=n; ++y) {
            for (int z =1; z <=n; ++z) {
                cin >> a[x][y][z];
            }
        }
    }

    //build 3d prefix sum array
    build_prefix_sum(n);

    int q;
    cin >> q;
    
    for (int i=0; i<q; i++) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << query_sum(lx, rx, ly, ry, lz, rz) << endl;
    }

    return 0;
}
