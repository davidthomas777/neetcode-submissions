class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size() - 1;
        while (start <= end) {
            // forgot to calculate mid in the while loop
            int mid = start + (end - start) / 2;

            if (matrix[mid][0] > target) {
                // forgot to subtract one from mid to avoid infinite loop
                end = mid - 1;
            }
            else if (matrix[mid][0] < target) {
                int _start = 0;
                int _end = matrix[mid].size() - 1;

                while (_start <= _end) {
                    // calculate mid in the while loop
                    int _middle = _start + (_end - _start) / 2;

                    if (matrix[mid][_middle] == target) {
                        return true;
                    }
                    else if (matrix[mid][_middle] > target) {
                        // decrement
                        _end = _middle - 1;
                    }
                    else {
                        // increment
                        _start = _middle + 1;
                    }
                }
                start = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
