class Solution {
private:
    std::vector<std::string> res;
    std::vector<std::string> st;
    
public:
    void backtrack(int openN, int closedN, int n) {
        if (openN == n && closedN == n) {
            std::string new_str = "";
            for (int i = 0; i < st.size(); i++) {
                new_str += st[i];
            }
            res.push_back(new_str);
            return;
        }
        if (openN < n) {
            st.push_back("(");
            backtrack(openN + 1, closedN, n);
            st.pop_back();
        }
        if (closedN < openN) {
            st.push_back(")");
            backtrack(openN, closedN + 1, n);
            st.pop_back();
        }
    }
    
    // backtracking problem
    std::vector<std::string> generateParenthesis(int n) {
        // keep track of how many brackets are opened and closed. Closed must always 
        // be less than the opened counter. and the opened must be less than n.
        // only add open parenthesis if open < n
        // only add a closing parenthesis if closed < open
        // valid if open == closed == n
        
        res.clear();  // Clear previous results
        st.clear();   // Clear previous stack
        
        backtrack(0, 0, n);
        return res;
    }
};