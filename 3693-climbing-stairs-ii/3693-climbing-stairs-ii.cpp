class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> cost(n+1);
        cost[0] = 0;
        for(int i=0; i<n; i++){
            cost[i+1] = costs[i];
        }
        vector<int> dp(n+1 , INT_MAX);

        dp[n] = 0;
        for(int idx=n-1; idx>=0; idx--){
            int singleJump = INT_MAX;
            if(idx+1 <= n) singleJump = cost[idx+1] + 1 + dp[idx+1];

            int doubleJump = INT_MAX;
            if(idx+2 <= n) doubleJump = cost[idx+2] + 4 + dp[idx+2];

            int tripleJump = INT_MAX;
            if(idx+3 <= n) tripleJump = cost[idx+3] + 9 + dp[idx+3];

            dp[idx] = min({singleJump, doubleJump, tripleJump});
        }
        return dp[0];
    }
};