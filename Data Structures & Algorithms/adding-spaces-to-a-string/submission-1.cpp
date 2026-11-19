class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        //spaces index
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            // if spaces index in bounds and current s index 
            // is in the spaces indicies
            if (j < spaces.size() && i == spaces[j]) {
                res += ' ';
                res += s[i];
                j++;
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};
