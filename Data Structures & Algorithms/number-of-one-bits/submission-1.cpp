class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // iterate through the bit
        for (int i = 0; i < 32; ++i) {
            // mask for each bit in the 32 bits
            uint32_t mask = (1u << i);
            bool bit_is_set = (n & mask) != 0;
            if (bit_is_set) {
                ++count;
            }
        }
        return count;
    }
};
