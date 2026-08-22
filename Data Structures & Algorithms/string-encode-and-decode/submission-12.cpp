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
            // converts the string length to an int
            int length = std::stoi(s.substr(i, j - i));
            // creates substring by indexing from j + 1 (position after #)
            // to the # of characters after it (length)
            std::string word = s.substr(j + 1, length);
            // append word to res list
            res.push_back(word);
            // update i by adding j + 1 (excluding #) and adding the length
            i = j + 1 + length;
        }
        return res;
    }
};
