class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0 , productSum = 1;
        int temp = n;
        while(temp > 0){
            int d = temp % 10;
            digitSum += d;
            productSum *= d;
            temp = temp / 10;
        }
        return !( n % (digitSum + productSum) );
    }
};