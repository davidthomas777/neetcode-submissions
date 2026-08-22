#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result = "";
        // iterate through each word in list
        // add length of word and # to beginning of each word in result string
        for (auto str : strs) {
            result += std::to_string(str.length()) + '#' + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        // result list
        std::vector<string> res;
        // counter
        int i = 0;
        while (i < s.length()) {
            int j = i;
            // incase length of str is more than 1 digit
            while (s[j] != '#') {
                j += 1;
            }
            int length = std::stoi(s.substr(i, j - i));
            std::string word = s.substr(j + 1, length);
            res.push_back(word);
            i = j + 1 + length;
        }
        return res;
    }
};
