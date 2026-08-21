class Solution {
public:
    long long countSmaller(long long mid, vector<int>& coins) {
        int n = coins.size();
        long long correctedCount = 0;

        for (int expr = 1; expr < (1 << n); expr++) {
            long long lcm = 1;
            int order = 0;

            for (int i = 0; i < n; i++) {
                // Check if ith bit is set
                if (expr & (1 << i)) {
                    order++;

                    long long g = gcd(lcm, (long long)coins[i]);

                    // Avoid overflow
                    if (lcm > mid / (coins[i] / g)) {
                        lcm = mid + 1;
                        break;
                    }

                    lcm = lcm / g * coins[i];
                }
            }

            if (lcm > mid)
                continue;

            if (order % 2 == 1)
                correctedCount += mid / lcm;
            else
                correctedCount -= mid / lcm;
        }

        return correctedCount;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high =
            (long long)*min_element(coins.begin(), coins.end()) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countSmaller(mid, coins) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};