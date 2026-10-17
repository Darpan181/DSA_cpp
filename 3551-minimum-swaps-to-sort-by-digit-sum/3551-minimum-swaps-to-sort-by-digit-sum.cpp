class Solution {
public:
    static int getDigitSum(int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }
    static bool comp(int a , int b){
        int digitSum1 = getDigitSum(a);
        int digitSum2 = getDigitSum(b);

        if(digitSum1 != digitSum2) return digitSum1 < digitSum2;
        return a < b;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSort(nums.begin() , nums.end());

        sort(afterSort.begin() , afterSort.end() , comp);

        unordered_map<int, int> valToIdx;
        for(int i=0; i<n; i++){
            valToIdx[nums[i]] = i;
        }

        int swap = 0;
        for(int i=0; i<n; i++){
            int expectedVal = afterSort[i];
            int currVal = nums[i];

            if(expectedVal == currVal) continue;

            int idx = valToIdx[expectedVal];
            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swap++;
        }
        return swap;
    }
};