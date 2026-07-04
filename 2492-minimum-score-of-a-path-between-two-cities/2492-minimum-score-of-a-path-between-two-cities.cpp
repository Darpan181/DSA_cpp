class Solution {
public:
    void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, int &ans){
        vis[node] = 1;
        for(auto it : adj[node]){
            int nxt = it.first;
            int dist = it.second;
            ans = min(ans, dist);
            if(!vis[nxt]) dfs(nxt, adj, vis, ans);
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n + 1];
        vector<int> vis(n + 1 , 0);
        int ans = INT_MAX;
        for(auto it : roads){
            int u = it[0] , v = it[1] , wt = it[2];
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        dfs(1, adj, vis, ans);
        return ans;
    }
};