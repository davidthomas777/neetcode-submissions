class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto p : mp) {
            if (p.second > nums.size() / 2) {
                return p.first;
            }
            std::cout << p.second << std::endl;
        }
        return 0;
    }
};