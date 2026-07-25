class Solution {
public:
    int find(int idx, int buy, vector<int> &arr, int n, int cap, vector<vector<vector<long long>>> &dp){
        if(cap == 0) return 0;
        if(idx == n) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        long long profit = 0;
        if(buy){
            profit = max(
                -arr[idx] + find(idx + 1, 0, arr, n, cap, dp),
                0 + find(idx + 1, 1, arr, n, cap, dp)
            );
        }
        else{
            profit = max(
                arr[idx] + find(idx + 1, 1, arr, n, cap - 1, dp),
                0 + find(idx + 1, 0, arr, n, cap, dp)
            );
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int cap = 2;
        vector<vector<vector<long long>>> dp(n , vector<vector<long long>> (2 , vector<long long> (3 , -1)));
        return find(0, 1, prices, n, cap, dp);
    }
};