class Solution {
public:
    int find(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(i == j) return arr[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = arr[i] + min(find(i + 2, j, arr, dp) , find(i + 1, j - 1, arr, dp));
        int take_j = arr[j] + min(find(i, j - 2, arr, dp) , find(i + 1, j - 1, arr, dp));

        return dp[i][j] = max(take_i , take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1 , -1));
        int totalSum = accumulate(nums.begin() , nums.end(), 0);

        int score1 = find(0 , n - 1, nums, dp);
        int score2 = totalSum - score1;

        return score1 >= score2;
    }
};