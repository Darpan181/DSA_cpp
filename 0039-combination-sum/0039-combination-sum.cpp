class Solution {
public:
    void solve(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int n){
        if(idx == n){
            if(target == 0) ans.push_back(ds);
            return;
        }

        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            solve(idx, target-arr[idx], arr, ds, ans, n);
            ds.pop_back();
        }
        solve(idx+1, target, arr, ds, ans, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans, n);
        return ans;
    }
};