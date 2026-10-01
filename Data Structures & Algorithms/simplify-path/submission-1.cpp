class Solution {
public:
    string simplifyPath(string path) {
        // . = current directory, ignore
        // .. = parent folder
        vector<string> st;
        path += '/';
        string curr = "";

        for (char c : path) {
            // if  slash
            if (c == '/') {
                // if current directory name is .., we pop last folder on stack
                // ensure stack isnt empty, cant pop the home folder
                if (curr == "..") {
                    if (!st.empty()) st.pop_back();
                }
                // if current directory name is not empty and isnt just a .
                else if (!curr.empty() && curr != ".") {
                    // add to stack of folder names
                    st.push_back(curr);
                }
                // clear current name of folder
                curr.clear();
            }
            // update current folder name with new character
            else {
                curr += c;
            }
        }
        string res = "/";
        int count = 0;
        for (string s : st) {
            res += s;
            if (count != st.size() - 1) {
                res += '/';
            }
            count++;
        }
        return res;
    }
};