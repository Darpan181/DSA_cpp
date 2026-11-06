class Solution {
public:
    static bool comp(vector<int> a , vector<int> b){
        return a[1] < b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> ids;
        for(int i=0; i<queries.size(); i++){
            ids.push_back({queries[i] , i});
        }
        sort(ids.begin() , ids.end());
        sort(logs.begin() , logs.end() , comp);

        int left = 0 , right = 0 , len = logs.size();
        int active = 0;
        vector<int> ans(queries.size());
        vector<int> hash(n+1 , 0);

        for(int i=0; i<queries.size(); i++){
            int q = ids[i].first;
            int idx = ids[i].second;
            while(right < len && logs[right][1] <= q){
                int id = logs[right][0];
                if(hash[id] == 0) active++;
                hash[id]++;
                right++;
            }

            while(left < right && logs[left][1] < q-x){
                int id = logs[left][0];
                hash[id]--;
                if(hash[id] == 0) active--;
                left++;
            }

            ans[idx] = n - active;
        }
        return ans;
    }
};