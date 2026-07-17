class Solution {
public:
    int find(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] = 1 + find(idx1 - 1, idx2 - 1, s1, s2, dp);
        return dp[idx1][idx2] = max( find(idx1 - 1, idx2, s1, s2, dp) , find(idx1, idx2 - 1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty() || text2.empty()) return 0;
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n , vector<int> (m , -1));
        return find(n - 1, m - 1, text1, text2, dp);
    }
};