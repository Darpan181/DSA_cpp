class Solution {
public:
    int find(vector<int> &arr, int idx, int sum, vector<vector<int>> &dp){
        if(idx == 0){
            if(sum % arr[0] == 0) return sum / arr[0];
            else return 1e9;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int notTake = find(arr, idx - 1, sum, dp);
        int take = INT_MAX;
        if(arr[idx] <= sum) take = 1 + find(arr, idx, sum - arr[idx], dp);
        return dp[idx][sum] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int> (amount + 1 , -1));
        int ans = find(coins, n - 1, amount, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};