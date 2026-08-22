class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;
        while (r - l >= k) {
            // if value at leftptr is closer to target x (abs difference is smaller)
            // than the value at rightptr, we move the right ptr to the left one
            if (abs(x - arr[l]) <= abs(x - arr[r])) {
                r--;
            }
            // vice-versa, move left ptr closer
            else {
                l++;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);

    }
};