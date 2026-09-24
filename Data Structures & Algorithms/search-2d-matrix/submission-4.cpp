class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int m = matrix.size();
        int n = matrix[0].size();
        while (l <= r) {
            int m = (r + l) / 2;
            if (matrix[m][0] == target || matrix[m][n-1] == target) return true;
            // use this current row for binary search
            if (matrix[m][0] < target && matrix[m][n-1] > target) {
                int left = 0;
                int right = n - 1;
                int mid;
                while (left <= right) {
                    int mid = (left + right) / 2; 
                    if (left == right && matrix[m][mid] != target) {
                        return false;
                    }
                    else if (matrix[m][mid] == target) {
                        return true;
                    }
                    else if (matrix[m][mid] < target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                return false;
            }
            // if result in lower row number
            else if (matrix[m][0] > target) {
                r = m - 1;
            }
            // if result in
            else if (matrix[m][n-1] < target){
                l = m + 1;
            }
        }
        return false;
    }
};
