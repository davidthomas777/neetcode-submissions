class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // [1, 2, 4, 5, 6, 3, 1]
        // [1, 2, 3, 4, 5, 6, 7]
        set<int> seen;
        int n = nums.size();

        for (int num : nums) {
            // if positive and hasnt been seen before
            if (num > 0 && seen.count(num) == 0) {
                seen.insert(num);
            }
        }
        if (seen.empty()) return 1;

        int i = 1;
        for (const auto& val : seen) {
            if (i != val) {
                return i;
            }
            i++;
        }
    }
};