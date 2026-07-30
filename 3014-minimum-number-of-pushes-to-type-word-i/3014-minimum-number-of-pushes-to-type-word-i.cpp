class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8)return n;
        long long ans=8;
        
        int remchar=n-8;
        int i=2;
        while(remchar>=8)
        {
            long long multi=(long long)i*8;
            ans+=multi;
            remchar-=8;
            i++;
        }
        
            long long multi=(long long)remchar*i;
        ans=ans+multi;
        return (int)ans;

    }
};