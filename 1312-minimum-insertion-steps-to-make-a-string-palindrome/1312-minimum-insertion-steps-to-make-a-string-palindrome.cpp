class Solution {
public:
    int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]) return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b, dp);
        else return dp[i][j] = max(lcs(i, j - 1, a, b, dp) , lcs(i - 1, j, a, b, dp));
    }
    int lps(string &s){
        int n = s.length();
        string s2 = "";
        for(int i=n-1; i>=0; i--) s2 += s[i];
        vector<vector<int>> dp(n , vector<int> (n , -1));
        return lcs(n - 1, n - 1, s, s2, dp);
    }
    int minInsertions(string s) {
        int n = s.length();
        return n - lps(s);
    }
};