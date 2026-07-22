class Solution {
public:
    long long find(int i, int j, string &a, string &b, vector<vector<long long>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j] = find(i - 1, j - 1, a, b, dp) + find(i - 1, j, a, b, dp);
        }
        else return dp[i][j] = find(i - 1, j, a, b, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length() , m = t.length();
        vector<vector<long long>> dp(n , vector<long long> (m , -1));
        return find(n - 1, m - 1, s, t, dp);
    }
};