class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string s : operations) {
            if (s == "+") {
                int res1 = st.top(); st.pop();
                int res2 = st.top();
                int sum = res1 + res2;
                st.push(res1);
                st.push(sum);      
            }
            else if (s == "D") {
                int res1 = st.top();
                st.push(res1 * 2);
            }
            else if (s == "C") {
                st.pop();
            }
            else {
                st.push(stoi(s));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};