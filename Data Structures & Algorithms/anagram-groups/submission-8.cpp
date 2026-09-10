class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // anagrams are strings that have the same character count, including
        // duplicates
        // iterate through list strs,
        // sort the current string, and add it to a hashmap and map its index value
        vector<vector<string>> res;
        unordered_map<string, vector<int>> mp;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            // map current string sorted to its index
            mp[curr].push_back(i);
        }
        // for each pairing in the map (string to its corresponding index for anagram)
        for (const auto& p : mp) {
            // create a vector for each entry
            vector<string> curr;
            for (int i : p.second) {
                // add the corresponding string to curr
                curr.push_back(strs[i]);
            }
            res.push_back(curr);
        }
        return res;
    }
};
