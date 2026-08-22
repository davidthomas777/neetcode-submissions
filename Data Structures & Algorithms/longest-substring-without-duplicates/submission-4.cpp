class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use sliding window here to find optimal solution
        // once we find duplicates, we remove elements from the left until there are no more dupes
        // use a set to determine if we have one of each char
        int l = 0;
        int res = 0;
        std::set<char> mySet;
        for (int r = 0; r < s.size(); r++) {
            while (mySet.count(s[r]) == 1) {
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
