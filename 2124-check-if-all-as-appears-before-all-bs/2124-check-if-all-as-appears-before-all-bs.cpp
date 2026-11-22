class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int bIdx = n;
        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                bIdx = i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                if(i > bIdx) return false;
            }
        }
        return true;
    }
};