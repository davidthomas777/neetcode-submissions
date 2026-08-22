#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto chr : s) {
            if (chr == '(' || chr == '[' || chr == '{') {
                st.push(chr);
            }

            else if (chr == ')' || chr == ']' || chr == '}') {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                if ((chr == ')' && top != '(') ||
                    (chr == ']' && top != '[') ||
                    (chr == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
