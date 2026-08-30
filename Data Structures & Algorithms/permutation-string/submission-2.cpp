class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> need(26, 0);
        vector<int> win(26, 0);
        for (char c : s1) {
            need[c - 'a']++;
        }
        int n = s1.size();
        for (int i = 0; i < s2.size(); i++) {
            win[s2[i] - 'a']++;
            // update window by removing the fist element in the window
            if (i >= n) win[s2[i - n] - 'a']--;
            if (i >= n - 1 && win == need) return true;
        }
        return false;
    }
};
