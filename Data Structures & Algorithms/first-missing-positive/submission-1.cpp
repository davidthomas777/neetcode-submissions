class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> seen;
        for (int num : nums)
            if (num > 0) seen.insert(num);

        int i = 1;
        for (int val : seen) {
            if (val != i) return i;
            i++;
        }
        return i;
    }
};