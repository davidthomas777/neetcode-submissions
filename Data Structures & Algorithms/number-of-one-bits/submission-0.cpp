class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            uint32_t mask = (1u << i);
            bool bit_is_set = (n & mask) != 0;
            if (bit_is_set) {
                ++count;
            }
        }
        return count;
    }
};
