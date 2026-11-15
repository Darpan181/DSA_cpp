class Solution {
public:
    static const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }

        int odd = 0 , even = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(prefixSum[i] % 2 != 0){
                odd++;
                ans = (ans + even + 1) % MOD;
            }
            else{
                even++;
                ans = (ans + odd) % MOD;
            }
        }
        return ans;
    }
};