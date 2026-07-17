class Solution {
public:
    int change(int target, vector<int>& coins) {
    int n = coins.size();
    vector <long long> dp(target+1,0);
    dp[0]= 1;
    for(int i=0;i<n;i++){
        for(int s =coins[i];s<=target;s++){
            dp[s]  += dp[s-coins[i]];
            if(dp[s]>INT_MAX) dp[s] =  INT_MAX;
        }
    }
    return (int)dp[target];
    }
};