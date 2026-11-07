class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size() , m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free; // {wt , idx}
        for(int i=0; i<n; i++){
            free.push({servers[i] , i});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy; //{time , idx}

        vector<int> ans(m);
        long long time = 0;
        for(int i=0; i<m; i++){
            time = max(time , (long long)i);

            while(!busy.empty()){
                if(busy.top().first <= time){
                    free.push({servers[busy.top().second] , busy.top().second});
                    busy.pop();
                }
                else break;
            }

            if(free.empty() == true){
                time = busy.top().first;
                while(!busy.empty() && busy.top().first <= time){
                    free.push({servers[busy.top().second] , busy.top().second});
                    busy.pop();
                }
            }

            ans[i] = free.top().second;
            busy.push({time + tasks[i] , free.top().second});
            free.pop();
        }
        return ans;
    }
};