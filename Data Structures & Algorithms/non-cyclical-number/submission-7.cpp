#include <vector>
#include <algorithm>
class Solution {
public:
    int calculate_sum_square(int number) {
        // result variable for calcualting sum of digits
        int result = 0;
        // take each digit of number with % and append its square to result, then integer divide by 10
        while (number != 0) {
            int digit = number % 10;
            result += digit * digit;
            number /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        // vector of seen numbers to avoid infinite loops
        std::vector<int> seen_nums;
        int result = n;
        // keep updating result until it becomes 1
        while (result != 1) {
            result = calculate_sum_square(result);
            // if we have seen it before, then return false
            if (std::find(seen_nums.begin(), seen_nums.end(), result) != seen_nums.end())  {
                return false;
            }
            // insert result into vectors after each iteration
            seen_nums.push_back(result);
        }
        return true;
    }
};
