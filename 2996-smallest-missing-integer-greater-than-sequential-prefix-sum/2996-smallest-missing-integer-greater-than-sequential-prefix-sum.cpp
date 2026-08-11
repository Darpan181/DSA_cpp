class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int sum = nums[0];
        unordered_set<int> st(nums.begin() , nums.end());
        for(i=1; i<n; i++){
            if(nums[i] == nums[i - 1] + 1) sum += nums[i];
            else break;
        }
        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};