class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int length = s.length();
        int l = 0;
        set<char> window;
        for (int r = 0; r < length; r++) {
            char c = s[r];
            while (window.count(c)) {
                window.erase(s[l]);
                l++;
            }
            window.insert(c);
            if ((r - l + 1) > res) {
                res = r - l + 1;
            }
        }
        return res;
    }
};
