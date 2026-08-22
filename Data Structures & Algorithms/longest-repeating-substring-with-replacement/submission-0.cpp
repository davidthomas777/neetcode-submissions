class Solution {
public:
    int characterReplacement(string s, int k) {
        // res variable
        int res = 0;
        // set of chars using characters from string s
        unordered_set<char> charSet(s.begin(), s.end());
        // iterate through each unique char
        for (char c : charSet) {
            // set count to 0 for each character that we check the count of
            int count = 0;
            // left pointer l
            int l = 0;
            // right pointer r
            for (int r = 0; r < s.size(); r++) {
                // if s[r] is c, increment count
                if (s[r] == c) {
                    count++;
                }
                
                // while window - count of current char is greater than k.
                while ((r - l + 1) - count > k) {
                    // decrement the count
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }
                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};
