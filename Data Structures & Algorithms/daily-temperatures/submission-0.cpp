class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // initialize array of size temperatures, initalized all to 0
        vector<int> res(temperatures.size(), 0);
        // pair: {temp, index}
        stack<pair<int, int>> st; 
        
        for (int i = 0; i < temperatures.size(); i++) {
            // gets current temp as t
            int t = temperatures[i];
            // while stack is not empty, and current temp is greater than the top of the stack temperature
            while (!st.empty() && t > st.top().first) {   
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }
            st.push({t, i});
        }
        return res;
    }
};
