class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = *max_element(nums.begin() , nums.end());
        int b = *min_element(nums.begin() , nums.end());

        while(b != 0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
};