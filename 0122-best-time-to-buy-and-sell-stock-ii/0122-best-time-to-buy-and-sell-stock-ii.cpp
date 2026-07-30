class Solution {
public:
    int solve(int idx,bool buy,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(idx>=prices.size()){
            return 0;

        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int pick=0;
        int not_pick=0;

        
        if(buy==true){
            pick=-prices[idx]+solve(idx+1,false,prices,dp);
            not_pick=solve(idx+1,true,prices,dp);
        }
        else
        {
            pick=prices[idx]+solve(idx+1,true,prices,dp);
            not_pick=solve(idx+1,false,prices,dp);
        }

        return dp[idx][buy]= max(pick,not_pick);

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,true,prices,dp);
    }
};