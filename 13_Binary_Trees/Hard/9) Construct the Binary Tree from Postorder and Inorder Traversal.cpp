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
    int postorderIndex;
    TreeNode* helper(vector<int>& postorder,int start,int end){
        if(start>end) return nullptr;
        int rootval = postorder[postorderIndex--];
        TreeNode* ans = new TreeNode(rootval);
        ans->right = helper(postorder,mp[rootval]+1,end);
        ans->left = helper(postorder,start,mp[rootval]-1);
        return ans;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        postorderIndex = postorder.size()-1;
        return helper(postorder,0,inorder.size()-1);
    }
};
