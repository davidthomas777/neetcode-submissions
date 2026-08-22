class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                string skipL = s.substr(l + 1, r - l);
                string skipR = s.substr(l, r - l);
                string revL = skipL, revR = skipR;
                reverse(revL.begin(), revL.end());
                reverse(revR.begin(), revR.end());
                return skipL == revL || skipR == revR;
            }
            l++;
            r--;
        }
        return true;
    }
};