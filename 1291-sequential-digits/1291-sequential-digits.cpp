class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";
        int lowlen = to_string(low).size();
        int highlen = to_string(high).size();

        for(int len=lowlen; len<=highlen; len++){
            for(int i=0; i+len <= 9; i++){
                int num = stoi(digits.substr(i , len));
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};