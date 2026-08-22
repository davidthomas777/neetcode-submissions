class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hashmap string to list of strings
        // this will create a unique key for each string based on the count of characters 
        //
        std::unordered_map<string, vector<string>> res;
        for (const auto & s : strs) {
            // tracks number of each character
            vector<int> count(26, 0);
            // for each character in string s
            for (char c : s) {
                // count and index of character is incremented by one
                count[c - 'a']++;
            }
            // create string key starting at count of index 0 (so either 1 or 0)
            string key = to_string(count[0]);
            // iterate through count and append either 1 or 0 to the key seperated by ,
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            // add the key and set the value to the string s
            res[key].push_back(s);
        }
        // create result list
        vector<vector<string>> result;
        // for each key, push back the value into result
        for (const auto & pair : res) {
            result.push_back(pair.second);
        }
        // return result
        return result;
    }
};
