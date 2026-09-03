class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        int n = nums.size();
        int target = n / 3;
        for (int num : nums) {
            mp[num]++;
        }
        for (pair<int, int> p : mp) {
            if (p.second > target) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};