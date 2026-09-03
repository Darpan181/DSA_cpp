class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0 , even = 0;
        int mini = INT_MAX;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            mini = min(mini , nums1[i]);
            if(nums1[i] % 2 == 0) even++;
            else odd++;
        }
        if(!even || !odd) return true;
        
        int flag = 0;
        if(mini % 2 != 0) flag = 1;

        for(int i=0; i<n; i++){
            if(nums1[i] % 2 == flag) continue;
            else{
                int sub = nums1[i] - mini;
                if(sub < 1 || (sub % 2 != flag)) return false;
            }
        }
        return true;
    }
};