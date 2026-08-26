class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0 , r = 0 , minlen = INT_MAX;
        int cnt = 0;
        string ans;
        while(r < n){
            if(s[r] == '1') cnt++;
            while(cnt > k){
                if(s[l] == '1') cnt--;
                l++;
            }
            if(cnt == k){
                while(s[l] == '0') l++;
                int len = r - l + 1;
                if(len == minlen){
                    string curr = s.substr(l, len);
                    if (curr < ans) ans = curr;
                }
                else if(len < minlen){
                    minlen = len;
                    ans = s.substr(l , minlen);
                }
            }
            r++;
        }
        return ans;
    }
};