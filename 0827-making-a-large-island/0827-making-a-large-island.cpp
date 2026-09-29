class DisjointSet{
public:
    vector<int> parent , size;
    DisjointSet(int n){
        size.resize(n , 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n){
        return row < n && row >= 0 && col < n && col >= 0;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;
                
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int idx=0; idx<4; idx++){
                    int newr = row + dr[idx];
                    int newc = col + dc[idx];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeNo = row*n + col;
                        int adjNodeNo = newr*n + newc;
                        ds.unionBySize(nodeNo , adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for(int idx=0; idx<4; idx++){
                    int newr = row + dr[idx];
                    int newc = col + dc[idx];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int size = 0;
                for(auto it : components){
                    size += ds.size[it];
                }
                mx = max(mx , size + 1);
            }
        }

        for(int cell=0; cell<n*n; cell++){
            mx = max(mx, ds.size[ds.findUPar(cell)]);
        }
        return mx;
    }
};