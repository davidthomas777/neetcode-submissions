class Solution {
public:
    string simplifyPath(string path) {
        /*
            '.' - current folder
            '..' - parent folder
            '//+' always should be treated as a single slash '/'
            /neetcode/practice//...///../courses ->
            /neetcode/practice/courses
            iterate through path string

        */
        vector<string> st;
        string curr;
        for (char c : path + "/") {
            if (c == '/') {
                if (curr == "..") {
                    if (!st.empty()) st.pop_back();
                } else if (!curr.empty() && curr != ".") {
                    st.push_back(curr);
                }
                curr.clear();
            } else {
                curr += c;
            }
        }
        string result = "/";
        for (int i = 0; i < st.size(); ++i) {
            if (i > 0) result += "/";
            result += st[i];
        }
        return result;
    }
};