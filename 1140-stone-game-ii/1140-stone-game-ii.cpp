class Solution {
public:
    int solve(int i, int person, vector<int> &piles, int M, int n, vector<vector<vector<int>>> &dp){
        if(i >= n) return 0;

        if(dp[i][person][M] != -1) return dp[i][person][M];

        int stones = 0;
        int result = person ? INT_MAX : -1;
        for(int x=1; x<= min(2*M, n-i); x++){
            stones += piles[i + x - 1];

            if(person == 0){
                result = max(result , stones + solve(i+x, 1, piles, max(M,x), n, dp));
            }
            else{
                result = min(result, solve(i+x, 0, piles, max(M,x), n, dp));
            }
        }
        return dp[i][person][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int M = 1;
        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>> (2 , vector<int> (n + 1 , -1)));
        return solve(0, 0, piles, M, n, dp);
    }
};