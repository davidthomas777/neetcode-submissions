class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return vector<int>(1, -1);

        vector<int> suffix_arr(n, -1);
        int max_val = 0;
        for (int i = n - 1; i >= 0; i--) {
            max_val = max(max_val, arr[i]);
            suffix_arr[i] = max_val;
        }

        vector<int> res;
        for (int i = 1; i < n; i++) {
            res.push_back(suffix_arr[i]);
        }
        res.push_back(-1);
        return res;
    }
};