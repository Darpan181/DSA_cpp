class Solution {
public:
    int find(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = arr[i] + min(find(i + 2, j, arr, dp) , find(i + 1, j - 1, arr, dp));

        int take_j = arr[j] + min(find(i, j - 2, arr, dp) , find(i + 1, j - 1, arr, dp));

        return dp[i][j] = max(take_i , take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n , vector<int> (n , -1));

        int total = accumulate(piles.begin() , piles.end() , 0);

        int nosA = find(0, n - 1, piles, dp);
        int nosB = total - nosA;

        return nosA > nosB;
    }
};