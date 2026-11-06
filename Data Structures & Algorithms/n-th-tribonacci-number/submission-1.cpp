class Solution {
    unordered_map<int, int> dp;
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // if we have seen this problem before
        if (dp.count(n)) return dp[n];
        // if not seen before, add it to map dp, then return it
        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};

// tribonacci(3)
// since 3 is not <= 2, and we havent seen it yet so far, we set dp[3] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3). when tribonacci(n-1) finishes it returns 1, same with n- 2, and n - 3 returns 0, so 1 + 1 + 0 = 2. at teh end we return dp[3] which is set to 2.