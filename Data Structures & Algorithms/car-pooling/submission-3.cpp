class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int start_from = INT_MAX;
        int end_to = 0;
        for (vector<int> v : trips) {
            start_from = min(start_from, v[1]);
            end_to = max(end_to, v[2]);
        }

        vector<int> res(end_to + 1, 0);

        for (vector<int> trip : trips) {
            int start = trip[1];
            int end = trip[2];
            for (int i = start; i < end; i++) {
                res[i] += trip[0];
            }
        }
        for (int curr_capacity : res) {
            if (curr_capacity > capacity) return false;
        }
        return true;
    }
};