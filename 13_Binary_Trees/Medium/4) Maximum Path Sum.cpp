
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
