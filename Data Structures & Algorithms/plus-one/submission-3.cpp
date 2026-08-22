class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            // if digit is less than 9, add one and dont carry
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // if digit is 9, set to 0 and keep iterating to see if it carries 
            // on
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
