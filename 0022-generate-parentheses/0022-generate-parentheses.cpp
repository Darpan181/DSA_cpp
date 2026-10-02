class Solution {
public:
    void solve(int n, int open, int close, vector<string> &ans, string& curr){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            solve(n, open+1, close, ans, curr);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            solve(n, open, close+1, ans, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(n, 0, 0, ans, curr);
        return ans;
    }
};