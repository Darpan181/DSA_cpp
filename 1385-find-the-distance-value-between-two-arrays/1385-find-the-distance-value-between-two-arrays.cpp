class Solution {
public:
    int upperBound(int x, vector<int> &arr){
        int low = 0 , high = arr.size() - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= x){
                ans = arr[mid];
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        sort(arr2.begin() , arr2.end());
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            int val = upperBound(arr1[i] - d, arr2);
            if(val > arr1[i] + d) cnt++;
        }

        return cnt;
    }
};