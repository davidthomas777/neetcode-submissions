#include <stack>
#include <cctype>
#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        
        stack<int> st;
        
        for (const string& token : tokens) {
            if (token == "+") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a + b);
            }
            else if (token == "-") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a - b);
            }
            else if (token == "*") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a * b);
            }
            else if (token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a / b);
            }
            else {
                // a number (could be negative or multi-digit)
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
