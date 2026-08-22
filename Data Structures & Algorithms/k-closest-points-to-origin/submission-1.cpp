class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // for each point in points, we measure the euclidean distance from (0, 0)
        // we pair the point to its distance, and add each pair to a min heap
        // pop k - 1 times and add each one to a res list and return that list

        // res list
        vector<vector<int>> res;
        // min heap of pairs of float (distance) and point (int)
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            minHeap.push({dist, i});
        }

        for (int i = 0; i < k; ++i) {
            int index = minHeap.top().second;
            res.push_back(points[index]);
            minHeap.pop();
        }
        return res;

    }
};
