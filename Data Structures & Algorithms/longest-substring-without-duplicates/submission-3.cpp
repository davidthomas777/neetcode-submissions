class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // iterate through every char in the string
        // if we have seen the char before, end current substring and move index up 1
        // we need to keep track of the longest sub string by an integer value
        // if we have not seen the char before, add it to the set of current seen chars. 
        // this set is cleared every time we check for a new sub string
        int longest = 0;
        for (int i = 0; i < s.size(); i++) {
            std::set<char> mySet;
            int str_size = 0;
            for (int j = i; j < s.size() && mySet.count(s[j]) == 0; j++) {
                mySet.insert(s[j]);
                str_size++;
            }
            longest = std::max(str_size, longest);
        }
        return longest;
    }
};
