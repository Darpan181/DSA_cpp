class Solution {
public:
    int findProd(int n){
        int prod = 1;
        while(n > 0){
            int d = n % 10;
            prod *= d;
            n = n / 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(findProd(n) % t == 0) return n;
            else n++;
        }
    }
};