class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int temp = (a & b) << 1;
            // a = xor (a b) (adds the 1s with 0s,)
            a = a ^ b;
            // adds the carries
            b = temp;
        }
        return a;
    }

};
