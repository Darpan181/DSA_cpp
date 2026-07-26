class Solution {
public:
    int find(int idx, int prev_idx, vector<int> &arr, int n, vector<vector<int>> &dp){
        if(idx == n) return 0;
        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
        int len = 0 + find(idx + 1, prev_idx, arr, n, dp);
        if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
            len = max(len , 1 + find(idx + 1, idx, arr, n, dp));
        }
        return dp[idx][prev_idx + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int> (n + 1 , -1));
        return find(0, -1, nums, n, dp);
    }
};