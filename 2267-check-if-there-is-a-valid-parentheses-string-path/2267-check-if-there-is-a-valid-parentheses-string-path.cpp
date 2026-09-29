class Solution {
public:
    bool solve(int row, int col, int noOB, vector<vector<char>> &grid, int n, int m, vector<vector<vector<int>>> &dp){
        if(noOB < 0) return false;
        if(row == n-1 && col == m-1){
            if(noOB == 0) return true;
            return false;
        }

        if(dp[row][col][noOB] != -1) return dp[row][col][noOB];

        bool right = false;
        if(col+1 < m){
            if(grid[row][col+1] == '(') right = solve(row, col+1, noOB+1, grid, n, m, dp);
            else right = solve(row, col+1, noOB-1, grid, n, m, dp);
        }

        bool down = false;
        if(row+1 < n){
            if(grid[row+1][col] == '(') down = solve(row+1, col, noOB+1, grid, n, m, dp);
            else down = solve(row+1, col, noOB-1, grid, n, m, dp);
        }

        return dp[row][col][noOB] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int noOB = 1;
        if(grid[0][0] == ')') return false;

        vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int> (n+m , -1)));

        return solve(0, 0, noOB, grid, n, m , dp);
    }
};