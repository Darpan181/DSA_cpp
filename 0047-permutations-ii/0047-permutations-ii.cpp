class Solution {
public:
    void solve(unordered_map<int, int> &mpp, vector<int> &temp, vector<vector<int>> &ans, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(auto &it : mpp){
            if(it.second == 0) continue;

            temp.push_back(it.first);
            mpp[it.first]--;
            solve(mpp, temp, ans, n);
            temp.pop_back();
            mpp[it.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int &it : nums){
            mpp[it]++;
        }
        vector<int> temp;
        vector<vector<int>> ans;
        solve(mpp, temp, ans, n);
        return ans;
    }
};