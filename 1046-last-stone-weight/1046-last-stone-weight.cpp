class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq(stones.begin() , stones.end());
        while(pq.size() > 1){
            int first = pq.top() ; pq.pop();
            int second = pq.top() ; pq.pop();
            int diff = abs(first - second);
            if(diff != 0){
                pq.push(diff);
            }
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};