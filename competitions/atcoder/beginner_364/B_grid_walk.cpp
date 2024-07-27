#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int h, w;

bool isValid(const vector<vector<char>>& grid, int curr_row, int curr_col) {
    if (curr_row<0 or curr_col<0 or curr_row>=h or curr_col>=w)
        return false;

    if (grid[curr_row][curr_col] == '#') {
        return false;
    }
 
    return true;
}



int main()
{
    cin >> h >> w;
    int si, sj;
    vector<vector<char>> grid(h, vector<char>(w));
    string x;
    
    cin >> si >> sj;
    si--;
    sj--;
    
    string row;
    for (int i=0; i<h; i++) {
        cin >> row;
        for (int j=0; j<w; j++) {
            char cell = row[j];
            grid[i][j] = cell;
        }
    }
    
    cin >> x;
    
    int n_row, n_col;
    for (int i=0; i<x.length(); i++) {
        if (x[i]=='U') {
            n_row = si-1;
            n_col = sj;
        } else if (x[i]=='D') {
            n_row = si+1;
            n_col = sj;
        } else if (x[i]=='L') {
            n_row = si;
            n_col = sj-1;
        } else {
            n_row = si;
            n_col = sj+1;
        }
        
        if (isValid(grid, n_row, n_col)) {
            si = n_row;
            sj = n_col;
        }
        
    }
    
    cout << si+1 << " " << sj+1 << endl;
    
    

    return 0;
}