#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    unordered_map<string, int> smap;
    int c = 0;

    int x;
    cin >> x;
    vector<pair<int, int>> good;

    for (int i=0; i<x; i++) {
        string a, b;
        cin >> a >> b;

        if (smap.find(a) == smap.end()) {
            smap[a] = c++;
        }
        if (smap.find(b) == smap.end()) {
            smap[b] = c++;
        }

        int idxa = smap[a];
        int idxb = smap[b];

        good.emplace_back(idxa, idxb);
    }

    int y;
    cin >> y;
    vector<pair<int, int>> bad;

    for (int i=0; i<y; i++) {
        string a, b;
        cin >> a >> b;

        if (smap.find(a) == smap.end()) {
            smap[a] = c++;
        }
        if (smap.find(b) == smap.end()) {
            smap[b] = c++;
        }

        int idxa = smap[a];
        int idxb = smap[b];

        bad.emplace_back(idxa, idxb);
    }

    int g;
    cin >> g;
    vector<int> group(c, -1); 
    cin.ignore(); 

    for (int i=0; i<g; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string student;
        int gnum = i; 
        while (iss >> student) {
            if (smap.find(student) == smap.end()) {
                smap[student] = c++;
            }
            int idx = smap[student];
            if (idx >= group.size()) {
                group.resize(idx + 1, -1); 
            }
            group[idx] = gnum; 
        }
    }

    int ans = 0;

    for (const auto& [idxa, idxb] : good) {
        if (group[idxa] != group[idxb]) {
            ans++; 
        }
    }

    for (const auto& [idxa, idxb] : bad) {
        if (group[idxa] == group[idxb]) {
            ans++; 
        }
    }

    cout << ans << endl;


    return 0;
}
