class Solution {
public:
    int climbStairs(int n) {
        // basically implement fibonacci sequence until n-1 times
        int one = 1;
        int two = 1;
        for (int i = 0; i < n - 1; i++) {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};
