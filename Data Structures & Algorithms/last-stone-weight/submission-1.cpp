class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        // push every stone in stones into maxHeap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if (first == second) {
                continue;
            }
            else {
                int diff = first - second;
                maxHeap.push(diff);
            }
        }
        if (maxHeap.empty()) return 0;
        else {
            return maxHeap.top();
        }        
    }
};
