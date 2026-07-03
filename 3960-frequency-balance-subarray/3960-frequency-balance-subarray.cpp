class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int l = 0; l < n; l++) {
            unordered_map<int, int> cnt;
            unordered_map<int, int> freq;

            for (int r = l; r < n; r++) {
                int x = nums[r];
                int oldFreq = cnt[x];

                if (oldFreq > 0) {
                    if (--freq[oldFreq] == 0)
                        freq.erase(oldFreq);
                }

                cnt[x]++;
                freq[cnt[x]]++;

                if (cnt.size() == 1) {
                    ans = max(ans, r - l + 1);
                }
                else if (freq.size() == 2) {
                    auto it = freq.begin();
                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;

                    int small = min(f1, f2);
                    int large = max(f1, f2);

                    if (large == 2 * small)
                        ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};