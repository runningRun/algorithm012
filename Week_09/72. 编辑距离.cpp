class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty())
            return word1.size() + word2.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < word1.size() + 1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < word2.size() + 1; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i < word1.size() + 1; ++i) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                if (word1[i-1] != word2[j-1])
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[word1.size()][word2.size()];
    }
};