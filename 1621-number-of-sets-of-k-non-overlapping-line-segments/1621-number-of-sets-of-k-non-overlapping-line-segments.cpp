class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k+1, vector<int> (n+1 , 0));

        for(int i=0; i<n; i++) dp[0][i] = 1;

        for(int cnt=1; cnt<=k; cnt++){

            vector<int> prevRowSum(n+1 , 0);
            for(int x=n-1; x>=0; x--){
                prevRowSum[x] = (prevRowSum[x+1] + dp[cnt-1][x]) % MOD;
            }

            for(int i=n-1; i>=0; i--){
                int take = prevRowSum[i+1];

                int skip = dp[cnt][i+1] % MOD;

                dp[cnt][i] = (take + skip) % MOD;
            }
        }
        return dp[k][0];
    }
};