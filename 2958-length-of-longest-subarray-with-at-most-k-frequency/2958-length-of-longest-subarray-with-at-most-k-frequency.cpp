class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int l = 0 , r = 0 , maxlen = INT_MIN;
        while(r < n){
            mpp[nums[r]]++;
            while(mpp[nums[r]] > k){
                mpp[nums[l]]--;
                l++;
            }
            maxlen = max(maxlen , r - l + 1);
            r++;
        }
        return maxlen;
    }
};