#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <algorithm>
 
typedef long long ll;
 
using namespace std;

bool is_palindrome(const string& s, int start, int k) {
    for (int i=0; i<k/2; i++) {
        //increment up to half of k because after this, if it is a pallindrome, other half must be equal
        if (s[start+i] != s[start+k-i-1]) {
            //checking if equal
            return false;
        }
    }
    return true;
}

ll valid_perms(int n, int k, string s) {
    //generating all permutations
    set<string> all_permutations;
    //start from smallest to get all permutations
    sort(s.begin(), s.end());

    do {
        all_permutations.insert(s); //repeatedly inserting permutations
    } while (next_permutation(s.begin(), s.end())); //built in function for next permutation
    //continues until false
        
    ll valid_count = 0;
    
    for (const string& perm : all_permutations) {
        bool has_pal = false;
        //going through all permutations
        for (int i=0; i<=n-k; i++) {
            //for each subsection of the permutation (based on i)
            if (is_palindrome(perm, i, k)) {
                has_pal = true;
                break;
            }
        }
        if (!has_pal) {
            //adding to answer
            valid_count += 1;
        }
    }
    
    return valid_count;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    cout << valid_perms(n, k, s) << endl;

    return 0;
    
}

