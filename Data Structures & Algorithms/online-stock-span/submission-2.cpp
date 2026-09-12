class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}
    
    int next(int price) {
        // always count todays span as less than or equal to itself
        int span = 1;
        // while stack isnt empty or the top price is less than or equal to
        // todays price
        while (!st.empty() && st.top().first <= price) {
            // increment span by the top of the stack
            span += st.top().second;
            // remove old pair
            st.pop();
        }
        // push new pair
        st.push({price, span});
        return span;
    }   
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */