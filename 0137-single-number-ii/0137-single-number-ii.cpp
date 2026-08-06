class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bitIndex=0; bitIndex<32; bitIndex++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i] & (1 << bitIndex)){
                    cnt++;
                }
            }
            if(cnt % 3 != 0){
                ans = ans | (1 << bitIndex);
            }
        }
        return ans;
    }
};