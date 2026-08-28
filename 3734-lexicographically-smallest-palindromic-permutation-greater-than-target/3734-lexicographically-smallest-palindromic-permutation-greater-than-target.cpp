class Solution {
public:
    bool solve(string &curr, vector<int> &count, string &target, int i, bool greater, string &result, int halflen, char midChar){
        if(curr.length() == halflen){
            string candidate = curr;
            string rightHalf = candidate;
            reverse(rightHalf.begin() , rightHalf.end());

            if(midChar != '$') candidate += midChar; 
            candidate += rightHalf;
            if(candidate > target){
                result = candidate;
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

            if(solve(curr, count, target, i + 1, isGreater, result, halflen, midChar)) return true;

            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> count(26 , 0);
        char midChar = '$';
        int n = s.size();
        int halflen = 0;
        for(auto it : s) count[it - 'a']++;
        int oddCount = 0;
        for(int c=0; c<26; c++){
            if(count[c] % 2 == 1){
                oddCount++;
                midChar = c + 'a';
            }
        }
        if(oddCount > 1) return "";
         
        for(int c=0; c<26; c++){
            count[c] /= 2;
        }
        halflen = n / 2;
        string curr , result;
        solve(curr, count, target, 0, false, result, halflen, midChar);
        return result;
    }
};