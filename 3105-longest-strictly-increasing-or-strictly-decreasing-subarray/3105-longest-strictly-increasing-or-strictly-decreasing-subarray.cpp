class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxCount1 = 1 , cnt1 = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                cnt1++;
                maxCount1 = max(maxCount1 , cnt1);
            }
            else{
                cnt1 = 1;
            }
        }

        int maxCount2 = 1 , cnt2 = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                cnt2++;
                maxCount2 = max(maxCount2 , cnt2);
            }
            else{
                cnt2 = 1;
            }
        }
        return max(maxCount1 , maxCount2);
    }
};