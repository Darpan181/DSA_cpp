class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        if(n >= 1000) count += (n - 999);
        if(n >= 1e6) count += (n - 999999);
        if(n >= 1e9) count += (n - 999999999);
        if(n >= 1e12) count += (n - 999999999999);
        if(n >= 1e15) count += (n - 999999999999999);
        return count;
    }
};