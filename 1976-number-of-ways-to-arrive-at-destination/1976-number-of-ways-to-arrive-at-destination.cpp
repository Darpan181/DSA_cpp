class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        int mod = 1e9 + 7;

        vector<long long> dist(n , LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n , 0);
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0 , 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node])
                continue;

            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                long long newDist = d + wt;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                    ways[v] = ways[node];
                    pq.push({dist[v] , v});
                }
                else if(dist[v] == newDist){
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};