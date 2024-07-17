class Solution {
public:
    void recurse(vector<char>& s, int l, int r) {
        if (l>=r) {
            return;
        }
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        recurse(s, l+1, r-1);
    }
    
    void reverseString(vector<char>& s) {
        recurse(s, 0, s.size()-1);
    }
};