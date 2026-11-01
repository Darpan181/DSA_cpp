class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9;
        for(int i=0; i<n; i++){
            mini = min(mini , nums[i]);
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += abs(nums[i] - mini);
        }

        return sum;
    }
};