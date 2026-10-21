class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string sortedStr(s.begin() , s.end());
        sort(sortedStr.begin() , sortedStr.end());

        if(s == sortedStr) return 0;
        if(n == 2 && s != sortedStr) return -1;

        char mx = 'a';
        char mn = 'z';
        for(int i=0; i<n; i++){
            mx = max(mx , s[i]);
            mn = min(mn , s[i]);
        }

        if(s[0] == mn || s[n-1] == mx) return 1;
        
        for(int i=1; i<n-1; i++){
            if(s[i] == mn || s[i] == mx) return 2;
        }

        return 3;
    }
};