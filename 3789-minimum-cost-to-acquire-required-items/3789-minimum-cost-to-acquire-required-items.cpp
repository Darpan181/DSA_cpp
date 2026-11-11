class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long first = 1LL *need1*cost1 + 1LL*need2*cost2;
        long long second = 1LL*costBoth * max(need1 , need2);
        long long common = min(need1 , need2);
        
        long long third = 1LL * costBoth * common;
        third += 1LL * (need1 - common) * cost1;
        third += 1LL * (need2 - common) * cost2;

        return min({first , second , third});
    }
};