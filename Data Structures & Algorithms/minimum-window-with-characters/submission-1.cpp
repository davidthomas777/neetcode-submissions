class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT;
        for (char c : t) {
            countT[c]++;
        }
        // empty map for current window counts
        unordered_map<char, int> window;
        // total chars mapped to count
        int have = 0;
        // how many distinct chars needed to match (not duplicates)
        int need = countT.size();
        // indices of smallest window
        pair<int, int> res = {-1, -1};
        // resLen set to max
        int res_len = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            // found all occurences of this distinct char
            if (countT.contains(c) && window[c] == countT[c]) {
                have++;
            }
            while (have == need) {
                // if length of window is less than current minimum
                // res length
                if ((r - l + 1) < res_len) {
                    res_len = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return res_len == INT_MAX ? "" : s.substr(res.first, res_len);
    }
};
