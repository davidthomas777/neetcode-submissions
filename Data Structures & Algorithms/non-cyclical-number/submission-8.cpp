class Solution {
public:
    int happy_val(int num) {
        string curr = to_string(num);
        int res = 0;
        for (char c : curr) {
            int digit = c - '0';
            res += digit * digit;
        }
        return res;
    }
    bool isHappy(int n) {
        set<int> seen;
        int curr = n;
        while (true) {
            curr = happy_val(curr);
            if (curr == 1) return true;
            else if (seen.count(curr)) return false;
            seen.insert(curr);
        }
    }
};
