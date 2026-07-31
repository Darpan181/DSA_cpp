class Solution {
public:
    static bool comp(string &s1 , string &s2){
        return s1.size() < s2.size();
    }
    bool isComparable(string &s1 , string &s2){
        if(s1.size() != s2.size() + 1) return false;
        int i = 0 , j = 0;
        while(i < s1.size()){
            if(j < s2.size() && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i == s1.size() && j == s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp);
        
        int n = words.size();
        vector<int> dp(n , 1);
        int len = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(isComparable(words[i] , words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            len = max(len , dp[i]);
        }
    return len;
    }
};