#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

//prefix and suffix sum array (efficient counting of strings) 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();


    //for each character, num of character counted before j
        //n+1 because no characters counted before start
        //i.e. pre[0][3] is amount of A up to third character (non inclusive)
    vector<vector<int>> pre(26, vector<int>(n+1, 0));
    //num of character after j
    vector<vector<int>> suf(26, vector<int>(n+1, 0));

    for (int i=1; i<=n; i++) {
        for (int c=0; c<26; c++) {
            //copy over the character's previous count (cumulative) (prefix part)
            pre[c][i] = pre[c][i-1];
        }
        //updates count by 1 for whichever character represented by s[i-1] (0=A, 1=B...)
        pre[s[i-1]-'A'][i]++;
    }
    //same as above but from the back
    for (int i=n-1; i>=0; i--) {
        for (int c=0; c<26; c++) {
            suf[c][i] = suf[c][i+1];
        }
        suf[s[i]-'A'][i]++;
    }

    ll count = 0;

    //j is constrained (must be middle value)
    for (int j=1; j<n-1; j++) {
        for (int ch=0; ch<26; ch++) {
            //multiply before and after the letter
                //since we are choosing the j value, we need to go through each character in the alphabet and see how many before and after for each j
            count += static_cast<long long>(pre[ch][j]) * suf[ch][j+1];
        }
    }

    cout << count << "\n";

    return 0;
}
