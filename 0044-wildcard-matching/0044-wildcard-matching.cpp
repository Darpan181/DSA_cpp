class Solution {
public:
    bool find(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >=0) return false;
        if(j < 0 && i>= 0){
            for(int k=0; k<=i; k++){
                if(a[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j] || a[i] == '?'){
            if(find(i - 1, j - 1, a, b, dp) == true) return dp[i][j] = true;
        }
        else if(a[i] == '*'){
            if(find(i, j - 1, a, b, dp) || find(i - 1, j ,a, b, dp) == true) return dp[i][j] = true;
        }
        else return dp[i][j] = false;
    return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(m , vector<int> (n , -1));
        return find(m - 1, n - 1, p, s, dp);
    }
};