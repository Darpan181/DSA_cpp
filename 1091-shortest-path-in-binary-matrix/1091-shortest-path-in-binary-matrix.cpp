class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;
        
        vector<vector<int>> dist(n , vector<int> (n , 1e9));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1 , {0 , 0}});
        while(!q.empty()){
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second. second;
            q.pop();

            if(row == n-1 && col == n-1){
                return d;
            }

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && d + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = d + 1;
                        q.push({dist[nrow][ncol] , {nrow , ncol}});
                    }
                }
            }
        }
        return -1;
    }
};