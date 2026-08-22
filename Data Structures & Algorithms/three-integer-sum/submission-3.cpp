#include <vector>
#include <set>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<std::vector<int>> set_vectors;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size() - 2; ++i) {
            // skip duplicates for i and j
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                    set_vectors.insert(triplet);
                    j++;
                    k--;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
            j++;
        }
        std::vector<std::vector<int>> res_list(set_vectors.begin(), set_vectors.end());
        return res_list;
    }
};
