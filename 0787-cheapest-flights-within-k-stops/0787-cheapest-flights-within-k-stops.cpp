class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            int u = it[0] , v = it[1] , wt = it[2];
            adj[u].push_back({v , wt});
        }

        vector<int> dist(n , 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0 , {src , 0}});

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int d = q.front().second.second;
            q.pop();

            for(auto it : adj[node]){
                if(d + it.second < dist[it.first] && stops <= k){
                    dist[it.first] = d + it.second;
                    q.push({stops + 1 , {it.first , dist[it.first]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};