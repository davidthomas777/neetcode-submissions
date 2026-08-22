class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // convert given vector to a set
        std::set<int> mySet(nums.begin(), nums.end());
        int longest = 0;
        for (auto num : mySet) {
            // check if start of sequence
            // check if n - 1 doesnt exist in the set
            if (mySet.count(num - 1) == 0) {
                int length = 0;
                // if we found a start, we update length by one every time
                // if num + length is in the mySet
                while (mySet.count(num + length)) {
                    length += 1;
                }
                // set longets to the max of longest and the current length
                longest = std::max(length, longest);
            }
        }
        return longest;
    }
};
