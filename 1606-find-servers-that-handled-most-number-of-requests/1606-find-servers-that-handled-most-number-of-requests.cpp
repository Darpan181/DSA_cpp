class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0; i<k; i++){
            available_servers.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;

        vector<int> reqCount(k , 0);

        for(int i=0; i<arrival.size(); i++){
            int time = arrival[i];
            while(!busyServers.empty() && busyServers.top().first <= time){
                int server = busyServers.top().second;
                busyServers.pop();
                available_servers.insert(server);
            }

            int target = i % k;
            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()) it = available_servers.begin();
            if(available_servers.empty()) continue;

            int targetServer = *it;
            available_servers.erase(it);
            busyServers.push({time + load[i] , targetServer});

            reqCount[targetServer]++;
        }
        vector<int> ans;
        int maxi = *max_element(reqCount.begin() , reqCount.end());
        for(int i=0; i<k; i++){
            if(reqCount[i] == maxi) ans.push_back(i);
        }
        return ans;
    }
};