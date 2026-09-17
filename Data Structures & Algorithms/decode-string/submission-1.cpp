class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string res = "";

        for (char c : s) {
            if (c == ']') {
                string curr = "";
                
                while (!st.empty() && st.top() != '[') {
                    curr.insert(0, 1, st.top());
                    st.pop();
                }
                st.pop();  // pop '['

                int k = 0, scalar = 1;
                while (!st.empty() && isdigit(st.top())) {
                    k += (st.top() - '0') * scalar;
                    st.pop();
                    scalar *= 10;
                }
                string repeated = "";
                for (int i = 0; i < k; i++) repeated += curr;
                for (char ch : repeated) st.push(ch);
            }
            else {
                st.push(c);
            }
        }
        // drain the stack — answer is bottom-to-top
        while (!st.empty()) {
            res.insert(0, 1, st.top());
            st.pop();
        }
        return res;
    }
};