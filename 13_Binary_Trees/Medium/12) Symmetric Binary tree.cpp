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
    bool helper(TreeNode* leftSide,TreeNode* rightSide){
        if(!leftSide&&!rightSide) return true;
        if((!leftSide||!rightSide)||(leftSide->val!=rightSide->val)) return false;
        return helper(leftSide->left,rightSide->right)&&helper(leftSide->right,rightSide->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};
