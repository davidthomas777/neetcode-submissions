class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        std::vector<pair<int, int>> pair_list;
        for (pair<int, int> item : map) {
            // swaps the first and second value of each pair in map
            // first value is frequency, second is its number
            pair_list.push_back({item.second, item.first});
        }

        // by default C++ behavior, it will sort the pairs based on first value in pairs
        // sorts from least to greatest
        std::vector<int> res;
        sort(pair_list.begin(), pair_list.end());
        int num_pairs = pair_list.size();
        for (int i = num_pairs - 1; i > num_pairs - 1 - k; i--) {
            res.push_back(pair_list[i].second);
        }
        return res;
    }
};
