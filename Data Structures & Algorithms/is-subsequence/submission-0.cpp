class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_length = s.length();
        int s_index = 0;
        for (char c : t) {
            if (c == s[s_index]) {
                s_index++;
            }
        }
        if (s_index == s_length) return true;
        else return false;
    }
};