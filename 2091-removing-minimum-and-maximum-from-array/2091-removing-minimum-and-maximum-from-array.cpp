class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX, maxi = INT_MIN;
        int minIdx = -1, maxIdx = -1;

        for (int i = 0; i < n; i++) {

            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIdx = i;
            }

            if (nums[i] < mini) {
                mini = nums[i];
                minIdx = i;
            }
        }

        int ans = 0;

        if (minIdx > maxIdx) {
            swap(minIdx, maxIdx);
        }

        int left = maxIdx + 1;
        int right = n - minIdx;
        int both = (minIdx + 1) + (n - maxIdx);

        ans = min({left, right, both});

        return ans;
    }
};