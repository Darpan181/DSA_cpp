class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m , vector<int> (n , 0));

        for(int i=0; i<n; i++){
            if(!vis[0][i] && grid[0][i] == 0) bfs(0, i, grid, vis, m, n);
        }
        for(int i=0; i<n; i++){
            if(!vis[m-1][i] && grid[m-1][i] == 0) bfs(m-1, i, grid, vis, m, n);
        }
        for(int i=0; i<m; i++){
            if(!vis[i][0] && grid[i][0] == 0) bfs(i, 0, grid, vis, m, n);
        }
        for(int i=0; i<m; i++){
            if(!vis[i][n-1] && grid[i][n-1] == 0) bfs(i, n-1, grid, vis, m, n);
        }

        int ans = 0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    ans++;
                    bfs(i, j, grid, vis, m, n);
                }
            }
        }
        return ans;
    }
};