class Solution {
public:
    bool checkValidString(string s) {
        // call dfs helper function
        return dfs(0, 0, s);
    }

    bool dfs(int i, int open, const string & s) {
        if (open < 0) return false;
        if (i == s.size()) return open == 0;

        // if s[i] chr is open bracket:
        if (s[i] == '(') {
            return dfs(i + 1, open + 1, s);
        }
        // if closed bracket:
        else if (s[i] == ')') {
            return dfs(i + 1, open - 1, s);
        }
        // if *:
        else {
            return dfs(i + 1, open, s) || dfs(i + 1, open + 1, s) || dfs(i + 1, open - 1, s);
        }
    }
};
