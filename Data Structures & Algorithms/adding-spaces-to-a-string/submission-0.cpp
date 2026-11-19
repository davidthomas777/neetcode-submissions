class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        /* "ReadMoreBooks"
        // spaces = [4, 8]
        // -> "Read More Books"
        // iterate using a left and right pointer
        // while left index is not equal to current space number (4 or 8)
        // increase left index
        // when at the index, save the current character, set current index to a space
        // and set the next index over to the original, repeat this all the way to the end of the string
        to do this process, we increase left and right pointer until right the r
        */
        int count = 0;
        for (int idx : spaces) {
            s.insert(idx + count, 1, ' ');
            count++;
        }
        return s;
    }
};
