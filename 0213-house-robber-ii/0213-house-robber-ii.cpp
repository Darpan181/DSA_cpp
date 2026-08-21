class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp)
    {
        if(idx<0)
        {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int pick=nums[idx]+solve(idx-2,nums,dp);
        int not_pick=solve(idx-1,nums,dp);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>arr1=nums;
        arr1.pop_back();
        vector<int>arr2;
        for(int i=1;i<n;i++)
        {
            arr2.push_back(nums[i]);
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int firstmax=solve(arr1.size()-1,arr1,dp1);
        int secmax=solve(arr2.size()-1,arr2,dp2);
        return max(firstmax,secmax);
    }
};