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
    int daimeter = 0;
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if(left+right>daimeter) daimeter = left+right;
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxDepth(root);
        return daimeter;
    }
};
