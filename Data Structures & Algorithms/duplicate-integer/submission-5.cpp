#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> my_set;
        for(auto num: nums) {
            my_set.insert(num);
        }
        if (my_set.size() != nums.size())
            return true;
        else
            return false;
    }
};
