class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int j, int dir, vector<vector<int>> &grid, int m, int n, vector<vector<vector<int>>> &dp){
        if(i >= m || j >= n) return 0;
        if(grid[i][j] == 1){
            if(dir == 0) return dp[i][j][dir] = solve(i+1, j, 1, grid, m, n, dp);
            else return dp[i][j][dir] = solve(i, j+1, 0, grid, m, n, dp);
        }

        if(dp[i][j][dir] != -1) return dp[i][j][dir];

        if(i == m-1 && j == n-1) return 1;

        int right = solve(i, j+1, 0, grid, m, n, dp);

        int down = solve(i+1, j, 1, grid, m, n, dp);

        return dp[i][j][dir] = (right + down) % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dir = 0;

        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int> (2 , -1)));

        return solve(0, 0, 0, grid, m, n, dp);
    }
};