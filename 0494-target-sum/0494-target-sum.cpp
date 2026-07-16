class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long totalSum = 0;
        for(int it : nums) totalSum += it;
        if(totalSum < abs(target))
            return 0;

        if((totalSum - target) % 2)
            return 0;
        long long sum = (totalSum - target) / 2;
        vector<vector<int>> dp(n , vector<int> (sum + 1 , 0));
        if(nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if(nums[0] != 0 && nums[0] <= sum)
            dp[0][nums[0]] = 1;

        for(int idx=1; idx<n; idx++){
            for(int s=0; s<=sum; s++){
                int notPick = dp[idx - 1][s];
                int pick = 0;
                if(nums[idx] <= s) pick = dp[idx - 1][s - nums[idx]];

                dp[idx][s] = notPick + pick;
            }
        }
        return dp[n - 1][sum];
    }
};