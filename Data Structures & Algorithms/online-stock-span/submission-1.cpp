class StockSpanner {
public:
    stack<int> last_prices;
    StockSpanner() {}
    
    int next(int price) {
        stack<int> copy = last_prices;
        int count = 1;
        while(!copy.empty()) {
            int curr = copy.top();
            copy.pop();
            if (curr > price) break;
            count++;
        }
        last_prices.push(price);
        return count;
    }   
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */