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
    int ans = INT_MIN;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int maxPathLeft = max(0,helper(root->left));
        int maxPathRight = max(0,helper(root->right));
        ans = max(ans,root->val+maxPathRight+maxPathLeft);
        return max(maxPathLeft,maxPathRight) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return ans;
    }
};
