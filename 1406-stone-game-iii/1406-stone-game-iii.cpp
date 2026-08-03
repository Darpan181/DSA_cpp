class Solution {
public:
    int find(int i, vector<int> &arr, int n, vector<int> &dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int result = arr[i] - find(i + 1, arr, n, dp);
        if(i + 1 < n)
            result = max(result, arr[i] + arr[i + 1] - find(i + 2, arr, n, dp));
        if(i + 2 < n)
            result = max(result, arr[i] + arr[i + 1] + arr[i + 2] - find(i + 3, arr, n, dp));

        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n , -1);
        int diff = find(0, arr, n, dp);

        if(diff > 0) return "Alice";
        else if(diff == 0) return "Tie";
        else return "Bob";
    }
};