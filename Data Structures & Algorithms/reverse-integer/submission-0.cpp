#include <string>
#include <algorithm>
class Solution {
public:
    int reverse(int x) {
        // mins and maxes of a 32 digit (signed) int
        int max = 2147483647;
        int min = -2147483648;
        bool is_negative = false;
        if (x < 0) {
            x = -x;
            is_negative = true;
        }
        std::string str_num = std::to_string(x);
        std::reverse(str_num.begin(), str_num.end());
        long reverse_num = std::stol(str_num);

        if (is_negative) {
            reverse_num = -reverse_num;
        }
        if (reverse_num > max || reverse_num < min) {
            return 0;
        }
        return reverse_num;
    }
};
