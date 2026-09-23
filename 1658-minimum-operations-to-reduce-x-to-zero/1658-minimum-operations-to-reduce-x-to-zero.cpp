class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long arrSum = accumulate(nums.begin() , nums.end() , 0);
        long long newSum = arrSum - x;

        if(newSum < 0) return -1;
        if(newSum == 0) return n;

        int l = 0 , r = 0 , maxlen = -1e9;
        long long sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum > newSum){
                sum -= nums[l];
                l++;
            }
            if(sum == newSum){
                maxlen = max(maxlen , r - l + 1);
            }
            r++;
        }
        if(maxlen == -1e9) return -1;
        return n - maxlen;
    }
};