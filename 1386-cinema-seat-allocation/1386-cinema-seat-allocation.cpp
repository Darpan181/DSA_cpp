class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<m;i++)
        {
            int row=reservedSeats[i][0];
            int seat=reservedSeats[i][1];
            mpp[row].push_back(seat);
        }
        int groups=0;
        for(auto it:mpp)
        {
            int row=it.first;
            auto seats=it.second;
            set<int>st;
            for(auto i:seats)
            {
                st.insert(i);
            }
            bool left=true;
            bool right=true;
            bool mid=true;
            for(auto seat:st)
            {
                if(seat>=2 && seat<=5)
                {
                    left=false;
                }
                if(seat>=4 && seat<=7)
                {
                    mid=false;
                }
                if(seat>=6 && seat<=9)
                {
                    right=false;
                }
            }
            int count=0;
            if(left)count++;
            if(right)count++;
            if(!left && mid && !right)
            {
                count=1;
            }
            groups+=count;

        }
        if(mpp.size()<n)
        {
            groups+=(n-mpp.size())*2;
        }
        return groups;
    }
};