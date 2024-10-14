#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

void rotate90Clockwise(vector<vector<int>>& grid, int n) {
    //transpose
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            swap(grid[i][j], grid[j][i]);
        }
    }
    //reverse
    for (int i=0; i<n; i++) {
        reverse(grid[i].begin(), grid[i].end());
    }
}

void printGrid(const vector<vector<int>>& grid) {
    for (auto row : grid) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] < grid[0][n-1] && grid[0][0] < grid[n-1][0] && 
        grid[n-1][0] < grid[n-1][n-1] && grid[0][n-1] < grid[n-1][n-1]) {
        printGrid(grid);
        return 0;
    }

    rotate90Clockwise(grid, n);
    if (grid[0][0] < grid[0][n-1] && grid[0][0] < grid[n-1][0] && 
        grid[n-1][0] < grid[n-1][n-1] && grid[0][n-1] < grid[n-1][n-1]) {
        printGrid(grid);
        return 0;
    }

    rotate90Clockwise(grid, n);
    if (grid[0][0] < grid[0][n-1] && grid[0][0] < grid[n-1][0] && 
        grid[n-1][0] < grid[n-1][n-1] && grid[0][n-1] < grid[n-1][n-1]) {
        printGrid(grid);
        return 0;
    }

    rotate90Clockwise(grid, n);
    printGrid(grid);

    return 0;
}
