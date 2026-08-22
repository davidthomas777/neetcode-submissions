class Solution {
public:
    int appendCharacters(string s, string t) {
        // we start with the first char of string t
        // we need to find out how many of the characters in t
        // are already in string s
        // coding -> coaching. since only co is the only subsequence in coaching from coding
        // we need to add d i n g to the end of coaching to get COachingDING
        // if t is already a subsequence in s, we return 0
        
        int num_chars = 0;
        int s_index = 0;
        int s_len = s.length();

        int t_index = 0;
        int t_length = t.length();
        
        // for each char in t
        for (char c : t) {
            // find first instance of matching char
            while (s_index < s_len && s[s_index] != c) {
                s_index++;
            }
            if (s_index == s_len) {
                // ran out of s: c and everything after it must be appended
                num_chars = t_length - t_index;
                break;
            }
            s_index++;   // consume the matched char
            t_index++;   // move past c in t
        }
        return num_chars;
    }
};