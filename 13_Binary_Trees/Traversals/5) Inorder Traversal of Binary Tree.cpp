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
    void helper(TreeNode* root,vector<int>& answer){
        if(root==nullptr) return ;
        helper(root->left,answer);
        answer.push_back(root->val);
        helper(root->right,answer);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root==nullptr) return answer;
        helper(root,answer);
        return answer;
    }
};
