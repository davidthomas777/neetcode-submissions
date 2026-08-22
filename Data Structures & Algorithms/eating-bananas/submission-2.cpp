class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        // finds max pile size
        int right = *max_element(piles.begin(), piles.end());
        // we set starting result to the max of the piles, b/c it works
        int res = right;
        // k can be from 1 to value of right

        while (left <= right) {
            int k = (left + right) / 2;
            // hours
            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            // if k eats all bananas in time, decrease rate until smallest solution
            if (totalTime <= h) {
                res = k;
                right = k - 1;
            }
            // if not, increase rate
            else {
                left = k + 1;
            }
        }
        // should finish when 
        return res;
    }
};
