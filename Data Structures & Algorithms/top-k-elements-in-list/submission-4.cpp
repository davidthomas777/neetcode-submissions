class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        std::vector<pair<int, int>> pair_list;
        std::vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // if we havent seen the number in nums, add a key to map
            if (map.count(nums[i]) == 0) {
                map[nums[i]] = 1;
            }
            // if we have seen, increment its value at that key num[i]
            else if (map.count(nums[i]) >= 1) {
                map[nums[i]]++;
            }
        }

        for (pair<int, int> item : map) {
            // swaps the first and second value of each pair in map
            // first value is frequency, second is its number
            pair_list.push_back({item.second, item.first});
        }
        // by default C++ behavior, it will sort the pairs based on first value in pairs
        // sorts from least to greatest
        sort(pair_list.begin(), pair_list.end());
        while (k > 0) {
            res.push_back(pair_list[pair_list.size() - 1].second);
            pair_list.pop_back();
            k--;
        }
        return res;
    }
};
