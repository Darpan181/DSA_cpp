class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        // edge case
        int flag = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return 0;

        int XOR = 0;
        for(int i=0; i<n; i++){
            XOR ^= nums[i];
        }
        if(XOR != 0) return n;
        else return n - 1;
    }
};