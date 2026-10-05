class Solution {
public:
    int solve(int &idx, string &s, int n){
        int score = 0;

        while(idx < n){
            if(s[idx] == '('){
                idx++;
                if(s[idx] == ')'){
                    score += 1;
                    idx++;
                }
                else score += 2 * solve(idx, s, n);
            }
            else{
                idx++;
                return score;
            }
        }
        return score;
    }
    int scoreOfParentheses(string s) {
        int n = s.length();
        int i = 0;
        return solve(i, s, n);
    }
};