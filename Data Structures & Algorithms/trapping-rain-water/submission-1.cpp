class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_rainwater = 0;

        if (n == 0) return 0;

        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        // fill the maxLeft vector for each i (left to right), the largest 
        // height to the left of index i
        // initialize furtherst left to height[0]
        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }

        // fill the maxRight vector for each i (right to left), the largest 
        // height to the right of index i
        // initialize furtherst right to height[n-1]
        maxRight[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        // for each index, we calculate total rainwater by the shorter
        // of the max walls to the left or right, then subtract height[i] from that
        // increment assign to total_rainwater
        for (int i = 0; i < n; ++i) {
            total_rainwater += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return total_rainwater;
    }
};
