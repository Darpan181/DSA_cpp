/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findSum_Nodes(TreeNode * root , int &sum, int &nodes){
        if(root == nullptr) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            
            sum += node->val;
            nodes++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    void solve(TreeNode * root , int &count){
        if(root == nullptr) return;
        int sum = 0;
        int nodes = 0;
        findSum_Nodes(root , sum , nodes);

        int avg = sum / nodes;
        if(avg == root->val) count++;

        if(root->left) solve(root->left, count);
        if(root->right) solve(root->right, count);
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        solve(root, count);
        return count;
    }
};