class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1_len = word1.length();
        int word2_len = word2.length();

        string res = "";
        // if strings have same length
        if (word1_len == word2_len) {
            for (int i = 0; i < word1_len; i++) {
                res += word1[i];
                res += word2[i];
            }
        }

        // if word1_len is shorter
        else if (word1_len < word2_len) {
            int i = 0;
            while (i < word1_len) {
                res += word1[i];
                res += word2[i];
                i++;
            }
            for (int j = i; j < word2_len; j++) {
                res += word2[j];
            }
        }

        // if word2_len is shorter
        else {
            int i = 0;
            while (i < word2_len) {
                res += word1[i];
                res += word2[i];
                i++;
            }
            for (int j = i; j < word1_len; j++) {
                res += word1[j];
            }
        }
        return res;
    }
};