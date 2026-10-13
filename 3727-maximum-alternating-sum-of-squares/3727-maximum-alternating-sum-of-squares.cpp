class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;

        for(int i=0; i<n; i++){
            if(nums[i] < 0) nums[i] = -nums[i];
            pq.push(nums[i]);
        }

        long long ans = 0;
        for(int i=1; i<= (n+1)/2; i++){
            long long top = pq.top();
            pq.pop();
            ans += (top * top);
        }

        while(!pq.empty()){
            long long top = pq.top();
            pq.pop();
            ans -= (top * top);
        }

        return ans;
    }
};