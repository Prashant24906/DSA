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
    unordered_map<int,int> mp;
    int preorderIndex;
    TreeNode* helper(vector<int>& preorder,int start,int end){
        if(start>end) return nullptr;
        int rootval = preorder[preorderIndex++];
        TreeNode* ans = new TreeNode(rootval);
        ans->left = helper(preorder,start,mp[rootval]-1);
        ans->right = helper(preorder,mp[rootval]+1,end);
        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        preorderIndex = 0;
        return helper(preorder,0,inorder.size()-1);
    }
};
