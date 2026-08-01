class Solution {
public:
    int find(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i > j) return 0;
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i; k<=j; k++){
            int cost = arr[j + 1] - arr[i - 1] + find(i, k-1, arr, dp) + find(k+1, j, arr, dp);
            mini = min(mini , cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c , vector<int> (c , -1));
        return find(1 , c - 2 , cuts , dp);
    }
};