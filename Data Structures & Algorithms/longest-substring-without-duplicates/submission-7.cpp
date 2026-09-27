class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int length = s.length();
        int l = 0;
        set<char> window;
        for (int r = 0; r < length; r++) {
            while (window.count(s[r])) {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
