class Solution {
public:
    bool is_even(int num) {
        if (num % 2 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        bool even = is_even(n);
        double sum = 1;

        if (n > 0) {
            while (n != 0) {
                sum *= x;
                n -= 1;
            }
        }

        else {
            while (n != 0) {
                sum /= x;
                n += 1;
            }
        }

        if (even == false && n < 0) {
            return -sum;
        }
        return sum;
    }
};
