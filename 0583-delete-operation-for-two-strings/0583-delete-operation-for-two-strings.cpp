class Solution {
public:
    int find(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1 + find(i - 1, j - 1, a, b, dp);
        else return dp[i][j] = max(find(i, j - 1, a, b, dp) , find(i - 1, j, a, b, dp));
    }
    int lcs(string &a, string &b){
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n , vector<int> (m , -1));
        return find(n - 1, m - 1, a, b, dp);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        int deletion = n - lcs(word1 , word2);
        int insertion = m - lcs(word1 , word2);

        return insertion + deletion;
    }
};