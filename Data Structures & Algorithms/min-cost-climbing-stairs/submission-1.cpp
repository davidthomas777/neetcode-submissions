class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // add 0 at the end 
        cost.push_back(0);
        // iterate backwards starting at 3rd to last index (2nd element from last)
        // [10, #15, 20] 0
        for (int i = cost.size() - 3; i >= 0; i--) {
            cost[i] += std::min(cost[i+1], cost[i+2]);
        }
        return std::min(cost[0], cost[1]);
    }
};
