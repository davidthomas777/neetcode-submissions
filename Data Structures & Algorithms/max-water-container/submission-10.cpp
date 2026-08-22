class Solution {
public:
    int maxArea(vector<int>& heights) {
        // index for start and end (l & r)
        int l = 0;
        int r = heights.size() - 1;
        // max area variable
        int max_area = 0;
        while (l < r) {
            // calculate current area at positions height[l] & height[r]
            int calculated_area = (r - l) * min(heights[l], heights[r]);
            // if current area greater than max, update it
            if (calculated_area > max_area) {
                max_area = calculated_area;
            }
            // if one value is smaller than the other, update the variable
            if (heights[l] < heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return max_area;
    }
};
