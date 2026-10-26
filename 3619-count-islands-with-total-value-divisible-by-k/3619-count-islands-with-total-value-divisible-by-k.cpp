class Solution {
public:
    long long bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n){
        queue<pair<int, int>> q;
        q.push({i , j});
        vis[i][j] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        long long sum = grid[i][j];
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]!=0){
                    sum += grid[nrow][ncol];
                    vis[nrow][ncol] = 1;
                    q.push({nrow , ncol});
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m , vector<int> (n , 0));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long sum = bfs(i, j, grid, vis, m, n);
                    if(sum % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};