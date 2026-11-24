class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            long long prod = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];

            for(int j=i+1; j<n; j++){
                prod = prod * nums[j];
                gcdVal = gcd(gcdVal , nums[j]);
                lcmVal = lcm(lcmVal , nums[j]);

                if(prod > gcdVal * lcmVal) break;

                if(prod == gcdVal * lcmVal) ans = max(ans , j - i + 1);
            }
        }
        return ans;
    }
};