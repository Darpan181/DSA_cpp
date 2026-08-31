/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1};
        ListNode * curr = head->next;
        ListNode * prev = head;
        vector<int> indicesCP;
        int idx = 0;
        while(curr->next != nullptr){
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
                indicesCP.push_back(idx);
            }
            idx++;
            prev = curr;
            curr = curr->next;
        }
        int n = indicesCP.size();
        if(n == 0 || n == 1) return {-1 , -1};
        int maxDist = indicesCP[n - 1] - indicesCP[0];
        int minDist = INT_MAX;
        for(int i=0; i<n-1; i++){
            minDist = min(minDist , indicesCP[i+1] - indicesCP[i]);
        }
        return {minDist , maxDist};
    }
};