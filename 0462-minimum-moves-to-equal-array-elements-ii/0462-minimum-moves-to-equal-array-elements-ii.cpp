class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int pivot = 0;
        if(n % 2 == 0) pivot = (nums[n/2 - 1] + nums[n/2]) / 2;
        else pivot = nums[n/2];

        int moves = 0;
        for(int i=0; i<n; i++){
            moves += abs(nums[i] - pivot);
        }
        return moves;
    }
};