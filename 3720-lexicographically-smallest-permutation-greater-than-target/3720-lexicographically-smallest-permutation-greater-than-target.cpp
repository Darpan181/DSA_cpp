class Solution {
public:
    bool solve(string &curr, vector<int> &count, string &target, int i, bool greater, string &result){
        if(i == target.size()){
            if(greater){
                result = curr;
                return true;
            }
            return false;
        }

        for(char ch='a'; ch<='z'; ch++){
            if(count[ch - 'a'] == 0) continue;
            if(greater == false && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, i + 1, isGreater, result)) return true;

            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26 , 0);
        for(auto it : s) count[it - 'a']++;
        string curr;
        string result = "";
        solve(curr, count, target, 0, false, result);
        return result;
    }
};