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
            // if there is a duplicate
            while (mySet.count(s[r]) == 1) {
                // shrink left window until duplicate is gone
                // erase from set
                mySet.erase(s[l]);
                // update left pointer for indexing
                l++;
            }
            mySet.insert(s[r]);
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
