#include <vector>
#include <algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        else {
            std::vector<char> s_vec;
            std::vector<char> t_vec;
            for (int i = 0; i < s.size(); i++) {
                s_vec.push_back(s[i]);
            }
            for (int j = 0; j < t.size(); j++) {
                t_vec.push_back(t[j]);
            }
            sort(s_vec.begin(), s_vec.end());
            sort(t_vec.begin(), t_vec.end());
            if (s_vec == t_vec)
                return true;
            else {
                return false;
            }
        }
    }
};
