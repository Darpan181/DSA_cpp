class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans = "";
        int count1 = 0 , count2 = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                count1++;
                if(count1 > 1){
                    ans += s[i];
                }
            }
            else if(s[i] == ')'){
                count2++;
                if(count2 < count1){
                    ans += s[i];
                }
                else if(count1 == count2){
                    count1 = 0;
                    count2 = 0;
                }
            }
        }
        return ans;
    }
};