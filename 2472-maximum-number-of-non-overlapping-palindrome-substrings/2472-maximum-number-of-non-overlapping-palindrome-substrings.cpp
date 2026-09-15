class Solution {
public:
    // pal[i][j] = -1 -> not calculated
    //              0 -> not palindrome
    //              1 -> palindrome
    int isPalindrome(int i, int j, string &s,
                     vector<vector<int>> &pal) {

        if (i >= j)
            return 1;

        if (pal[i][j] != -1)
            return pal[i][j];

        if (s[i] != s[j])
            return pal[i][j] = 0;

        return pal[i][j] = isPalindrome(i + 1, j - 1, s, pal);
    }

    int solve(int idx, string &s, int k, vector<int> &dp, vector<vector<int>> &pal) {
        int n = s.length();

        if (idx >= n)
            return 0;

        if (dp[idx] != -1) return dp[idx];

        int ans = solve(idx + 1, s, k, dp, pal);

        for (int end = idx + k - 1; end < n; end++) {

            if (isPalindrome(idx, end, s, pal)) {
                ans = max(ans, 1 + solve(end + 1, s, k, dp, pal));
            }
        }
        return dp[idx] = ans;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<int> dp(n, -1);
        vector<vector<int>> pal(n, vector<int>(n, -1));

        return solve(0, s, k, dp, pal);
    }
};