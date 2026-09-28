class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int count = 0 , maxCount = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                count++;
                maxCount = max(count , maxCount);
            }
            else if(s[i] == ')'){
                count--;
            }
        }
        return maxCount;
    }
};