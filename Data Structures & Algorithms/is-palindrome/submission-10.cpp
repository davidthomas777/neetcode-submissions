#include <string>

class Solution {
public:
    bool isPalindrome(string s) {
        string my_str = "";
        for (char c: s) {
            if (isalnum(c)) {
                my_str += tolower(c);
            }
        }
        return my_str == string(my_str.rbegin(), my_str.rend());
    }
};
