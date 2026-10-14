class Solution {
public:
    int noOfDigits(int x){
        int cnt = 0;
        while(x > 0){
            x = x / 10;
            cnt++;
        }
        return cnt;
    }
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int n = noOfDigits(sum);

        if(num < n) return ans;
        if(num*9 < sum) return ans;

        while(sum >= 9){
            ans += '9';
            sum -= 9;
        }
        if(sum > 0) ans += (sum + '0');
        int remDigits = num - ans.length();

        while(remDigits > 0){
            ans += '0';
            remDigits--;
        }

        return ans;
    }
};