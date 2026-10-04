class Solution {
public:
    bool solve(int idx, int open, string &s, int n, vector<vector<int>> &dp){
        if(open < 0) return false;
        if(idx > n) return false;
        if(idx == n){
            if(open == 0) return dp[idx][open] = true;
            else return dp[idx][open] = false;
        }

        if(dp[idx][open] != -1) return dp[idx][open];

        if(s[idx] == '(') return dp[idx][open] = solve(idx+1, open+1, s, n, dp);
        else if(s[idx] == ')') return dp[idx][open] = solve(idx+1, open-1, s, n, dp);
        else{
            bool openB = solve(idx+1, open+1, s, n, dp);
            bool closeB = solve(idx+1, open-1, s, n, dp);
            bool skip = solve(idx+1, open, s, n, dp);
            return dp[idx][open] = openB || closeB || skip;
        }
    }
    bool checkValidString(string s) {
        int n = s.length();
        int open = 0;
        vector<vector<int>> dp(101, vector<int> (101, -1));
        return solve(0, open, s, n, dp);
    }
};