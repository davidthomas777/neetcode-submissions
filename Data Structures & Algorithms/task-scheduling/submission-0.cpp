class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // create a heap of most frequent letters first
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }


        // create a maxHeap of each entry of tasksa
        priority_queue<int> maxHeap;
        for (int cnt : count) {
            // only add to queue if 1 or more tasks
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        // <task count, idle time>
        queue<pair<int, int>> q;

        // while maxHeap or queue is NOT empty
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            }
            else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
