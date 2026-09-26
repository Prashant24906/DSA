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
    void helper(TreeNode* root,int& ans,int &cnt,int k){
        if(root == nullptr) return ;
        helper(root->left,ans,cnt,k);
        cnt++;
        if(cnt == k) ans = root->val;
        helper(root->right,ans,cnt,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans ;
        int cnt = 0;
        helper(root,ans,cnt,k);
        return ans;
    }
};
