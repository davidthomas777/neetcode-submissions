class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i - 1][1] >= intervals[i][0]) {
                intervals[i][0] = std::min(intervals[i-1][0], intervals[i][0]);
                intervals[i][1] = std::max(intervals[i-1][1], intervals[i][1]);
                intervals.erase(intervals.begin() + i - 1);
            }
            else {
                i++;
            }
        }
        return intervals;
    }
};
