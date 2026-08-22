class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        // we start at index 0, for each string at index 0, ensure they all
        // are the same character, if so, we add that char to res,
        // if one differs, we stop and return what we have
        int index = 0;
        bool difference = false;
        while (!difference) {
            if (index >= strs[0].size()) break;
            char current = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                if (index >= strs[i].size() || strs[i][index] != current) {
                    difference = true;
                    break;
                }
            }

            if (difference == false) {
                index++;
                res += current;
            }
        }
        return res;
    }
};