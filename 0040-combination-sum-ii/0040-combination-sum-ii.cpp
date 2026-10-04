class Solution {
public:
    void solve(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int n){
        if(target == 0){
            ans.push_back(ds);
            return;
        }    
        for(int i=idx; i<n; i++){
            if(i > idx && arr[i] == arr[i - 1]) continue;
            if(arr[i] <= target){
                ds.push_back(arr[i]);
                solve(i+1, target-arr[i], arr, ds, ans, n);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans, n);
        return ans;
    }
};