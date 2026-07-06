class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , maxlen = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                count++;
                maxlen = max(count , maxlen);
            }
            else count = 0;
        }
        return maxlen;
    }
};