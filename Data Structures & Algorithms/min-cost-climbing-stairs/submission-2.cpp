class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // add 0 at the end for final floor index
        cost.push_back(0);
        // iterate backwards starting at 3rd to last index (2nd element from last)
        for (int i = cost.size() - 3; i >= 0; i--) {
            // at each value in cost, add the minimum of the jumps ahead of it either 1 or 2
            cost[i] += std::min(cost[i+1], cost[i+2]);
        }
        // return min of cost[0] and cost[1] bc you can start at either index 
        return std::min(cost[0], cost[1]);
    }
};
