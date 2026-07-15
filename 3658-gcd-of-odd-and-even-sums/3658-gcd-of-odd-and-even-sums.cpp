class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long evenSum = 0 , oddSum = 0;
        for(int i=1; i<=n; i++){
            evenSum += (2 * i);
            oddSum += (2 * i - 1);
        }
        while(evenSum != 0){
            long long rem = oddSum % evenSum;
            oddSum = evenSum;
            evenSum = rem;
        }
        return oddSum;
    }
};