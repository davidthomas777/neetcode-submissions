#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int max_profit = 0;
        int left = 0;
        int right = 1;

        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            else {
                int curr_profit = prices[right] - prices[left];
                max_profit = std::max(max_profit, curr_profit);
            }
            right++;
        }
        return max_profit;
    }
};
