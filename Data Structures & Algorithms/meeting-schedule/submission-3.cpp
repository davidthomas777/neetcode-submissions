/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include <algorithm>

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort the vectors by their start times
        if (intervals.empty()) {
            return true;
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval & a, const Interval & b) 
        { return a.start < b.start; });

        for (size_t i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }
        return true;
    }
};
