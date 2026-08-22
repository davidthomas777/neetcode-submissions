#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> myHash;
        for (int num : nums) {
            myHash[num]++;
        }
        
        // Create a vector of pairs (number, frequency)
        std::vector<std::pair<int, int>> freqPairs;
        for (const auto& pair : myHash) {
            freqPairs.push_back({pair.first, pair.second});
        }
        
        // Sort by frequency in descending order
        std::sort(freqPairs.begin(), freqPairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second > b.second;
            });
        
        // Take the top k elements
        std::vector<int> result;
        for (int i = 0; i < k && i < freqPairs.size(); i++) {
            result.push_back(freqPairs[i].first);
        }
        
        return result;
    }
};
