class Solution {
public:
    int solve(int i , int j1 , int j2 , vector<vector<int>> &grid , int n , int m , int dj[], vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
        if(i == n - 1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        for(int d1=0; d1<3; d1++){
            for(int d2=0; d2<3; d2++){
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + solve(i + 1, j1+dj[d1], j2+dj[d2], grid, n, m, dj, dp));
                else maxi = max(maxi , grid[i][j1] + grid[i][j2] + solve(i + 1, j1+dj[d1], j2+dj[d2], grid, n, m, dj, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int dj[] = {-1 , 0 , 1};
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
        return solve(0 , 0 , m - 1 , grid , n , m , dj, dp);
    }
};